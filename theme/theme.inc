<?php
/**
 * @file theme.inc
 * 
 * Preprocessing to provide variables to sws template files.
 */

/**
 * Implementation of template_preprocess().
 */
function template_preprocess_sws_video(&$variables) {
  $node = $variables['node'];
 
  // get variables stored in node object to pass to theme function
  $video_url = $node->field_video_url[0]['safe'];
  if ($video_url) {
    $url = check_url($video_url);
    $size = $node->field_video_size[0]['safe'];
    $autoplay = check_plain($node->field_video_autoplay[0]['value']);
    $text = "[video: $url $size autoplay:$autoplay]";

    // call theme function provided by video_filter module 
    $video = video_filter_filter('process', 0, -1, $text);

    // default to align left if no alignment is set
    $align = $node->field_video_align[0]['safe'];
    $align = ($align) ? $align : 'left';

    // pass vars to sws-video-field.tpl.php 
    $variables['video_url'] = $video_url;
    $variables['video'] = $video; 
    $variables['align'] = $align;
  }
}

/**
 * Implementation of template_preprocess(). 
 */
function template_preprocess_sws_pic(&$variables) {
  $node = $variables['node'];

  // pics
  $pics = $node->field_pic;
  if ($pics[0]) { // make sure there are pictures to theme here
    // imagecache preset
    $preset_namespace = content_format('field_pic_size', $node->field_pic_size[0]);
    $preset_namespace = strip_tags($preset_namespace);
    $preset_namespace = trim($preset_namespace);
    // alignment
    $align = $node->field_pic_align[0]['safe'];

    $i = 0;
    $x = 'odd';
    foreach ($pics as $field_pic){
      $image_filepath = $field_pic['filepath'];
      $alt = $field_pic['data']['alt'];
      $title = $field_pic['data']['title'];
      $attributes = ''; // TODO handle attributes
      if ($align == 'alternate') {
        $side = ($x == 'odd') ? 'left' : 'right';
        $output .=  "<div class='pic pic-$align-$side' id='pic-$i'>";
      } else {
        $side = $align;
        $output .=  "<div class='pic pic-$align-$side' id='pic-$i'>";
      }
      $pic = theme('imagecache', $preset_namespace, $image_filepath, $alt, $title, $attributes);
      $pics[] = $pic;
      $output .= $pic;

      // caption
      $description = $field_pic['data']['description'];
      $description = check_markup($description);
      if ($description) {
        // set width for caption at width of picture.
        $image = image_get_info(imagecache_create_path($preset_namespace, $image_filepath)); 
        $width = $image['width'];
        // $height = $image['height'];
        $output .= "<div class='pic-caption' style='max-width:". $width. "px'>". $description ."</div>";
      }   

      $output .= '</div>';
      $i++;
      $x = ($x == 'even') ? 'odd' : 'even';
    }
  // pass vars to sws-video-field.tpl.php 
  $variables['output'] = $output;
  $variables['pics'] = $pics;
  $variables['align'] = $align;
  $variables['size'] = $preset_namespace; 
  }
}

/**
 * Implementation of template_preprocess().
 */
function template_preprocess_sws_map(&$variables) {
  $node = $variables['node'];
  $type = $node->type;

  // note: embed_gmap takes care of handles filtering
  $map =  content_format('field_map', $node->field_map[0]);
  $variables['map'] = $map;
  $variables['type'] = $type;
}

/**
 * Implementation of template_preprocess().
 */
 // todo Move to press_releases module
function template_preprocess_sws_pr_header(&$variables) {
  $node = $variables['node'];
  $variables['org'] = variable_get('press_releases_header', NULL);
  $variables['dept'] = variable_get('press_releases_subhead', NULL);
  $variables['headline'] = $node->title;
  $variables['subhead'] = $node->field_pr_subhead[0]['safe'];
  $variables['status'] = $node->field_pr_status[0]['safe'];
  // There may be many contacts
  foreach ($node->field_pr_contact as $contact) {
    $variables['contact'][] = $contact['safe'];
  }
  // Format date from unix timestamp
  $d = getdate($node->field_pr_datestamp[0]['value']);
  $date = $d['month'] .' '. $d['mday'] .', '. $d['year'];
  $variables['date'] = $date;
}

/**
 * Implementation of template_preprocess().
 */
function template_preprocess_sws_pr_footer(&$variables) {
  $variables['footer'] = check_markup(variable_get('press_releases_footer', NULL));
}

/**
 * Implementation of template_preprocess().
 */
function template_preprocess_sws_newsclip_header(&$variables) {
  $node = $variables['node'];

  // org info
  $org_node = node_load($node->field_news_org[0]['nid']);
  $b = sws_news_org_info($org_node);
  $org_name = $b->org_name; 
  $org_name_link = $b->org_name_link;
  $org_type = $b->org_type;
  // use image with link to org's website if available
  $banner = $b->banner;  
  $banner_link = $b->banner_link;  
  $display_banner = $b->display_banner;
  $org_website = $b->website; 

  // news clip info
  // Format date from unix timestamp
  $d = getdate($node->field_newsclip_date[0]['value']);
  $date = $d['weekday'] .', '. $d['month'] .' '. $d['mday'] .', '. $d['year'];
  // headline + subhead
  $headline = check_plain($node->title);
  $subhead = $node->field_news_subhead[0]['safe'];
  // external links
  $clip_website = $node->field_newsclip_url[0]['safe'];
  if ($clip_website) {
    $clip_website = url($clip_website, array('external' => TRUE));
    $options = array(
      'attributes' => array(
        'class' => 'news-headline-link',
        'target' => '_blank',
      ),
    );
    $headline_link = l($headline, $clip_website, $options);
    $subhead_link = l($subhead, $clip_website, $options);
  }

  // News Contact 
  /*
  // @todo 
    // The News Contact node type is not in use. We can probably 
    // remove this. No production
    // sites are currently integrating with Pylons CRM.In Feb 2011
    // These lines started coughing up ugly error messages on
    // one live website.
  // 
  foreach ($node->field_news_contact as $author_nid) {
    $author_node = node_load($author_nid);
    $author[] = check_plain($author_node->title);
  }
  // */

  // By Line
  $by = $node->field_news_by[0]['safe'];

  $variables['org_name'] = $org_name; 
  $variables['org_name_link'] = $org_name_link; 
  $variables['org_type'] = $org_type;
  $variables['banner'] = $banner; 
  $variables['banner_link'] = $banner_link; 
  $variables['display_banner'] = $display_banner; 
  $variables['org_website'] = $org_website; 
  $variables['clip_website'] = $clip_website; 
  $variables['date'] = $date; 
  $variables['headline'] = $headline; 
  $variables['headline_link'] = $headline_link; 
  $variables['subhead'] = $subhead; 
  $variables['subhead_link'] = $subhead_link; 
  $variables['author'] = $author; 
  $variables['by'] = $by; 
}

/**
 * Implementation of template_preprocess().
 */
function template_preprocess_sws_newsclip_footer(&$variables) {
  $variables['footer'] = check_markup(variable_get('news_clips_footer', NULL));
}

/**
 *  Implementation of template_preprocess().
 */
function template_preprocess_sws_news_org_banner(&$variables) {
  $node = $variables['node'];

  // Get banner and related variables from news organization node
  $b = sws_news_org_info($node);  

  // pass vars to .tpl.php 
  $variables['banner'] = $b->banner;
  $variables['banner_link'] = $b->banner_link; 
  $variables['size'] = $b->size; 
  $variables['website'] = $b->website; 
}

/**
 * theme banner (for use by multiple template_preprocess functions)
 */
function sws_news_org_info($node) {
  // banner
  $banner = $node->field_news_org_logo[0];
  if ($banner) { // make sure there is a banner to theme here
    // imagecache preset
    $preset_namespace = content_format('field_pic_size', $node->field_pic_size[0]);
    $preset_namespace = strip_tags($preset_namespace);
    $preset_namespace = trim($preset_namespace);

    $image_filepath = $banner['filepath'];
    $alt = $node->title; // use org name for alt
    $title = $banner['data']['title'];
    $attributes = ''; // TODO handle attributes

    $banner = theme('imagecache', $preset_namespace, $image_filepath, $alt, $title, $attributes);
  } 

    // website
    $website = $node->field_news_org_website[0]['value'];
    if ($website) {
      $options = array(
        'external' => TRUE, 
       );
      $website = url($website, $options);
      // create link on banner
      $options = array('html' => TRUE, 'attributes' => array('target' => '_blank'));
      if ($website && $banner) {
        $banner_link = l($banner, $website, $options);
      }
    }
  $org_name = check_plain($node->title);

  $b->banner = ($banner) ? $banner : '';
  $b->banner_link = ($banner_link) ? $banner_link : '';
  $b->website = ($website) ? $website : ''; 
  $b->size = ($preset_namespace) ? $preset_namespace : '';
  $b->display_banner = $node->field_news_display_banner[0]['value'];
  $b->org_name = $org_name;
  $b->org_name_link = ($website) ? l($org_name, $website, $options) : '' ;
  $b->org_type = check_plain($node->field_news_org_type[0]['value']);

  return $b;
}
