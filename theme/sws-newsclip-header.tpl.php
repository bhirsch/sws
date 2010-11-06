<?
// $Id$

/**
 * @file sws-newsclip-header.tpl.php
 * Default theme implementation to display news clip header. 
 *
 * Available variables:
 * - $node: The node object.
 * - $org_name
 * - $org_name_link
 * - $org_type
 * - $banner
 * - $banner_link
 * - $display_banner
 * - $org_website
 * - $clip_website
 * - $date
 * - $headline
 * - $headline_link
 * - $subhead
 * - $subhead_link
 * - $author: array of news contacts (if enabled)
 * - $by (string of authors)
 * 
 * @see template_preprocess_sws_newsclip()
 */
?>

<div class="news-clip-header <?php print "org-type-$org_type"?>">

  <div class="news-clip-banner">
    <?php if ($display_banner && $banner_link) : ?>
      <div class="news-org-logo"><?php print $banner_link ?></div>
    <?php elseif ($display_banner && $banner) : ?>
      <div class="news-org-logo"><?php print $banner ?></div>
    <?php elseif ($org_name_link) : ?>
      <div class="news-org-name"><?php print $org_name_link ?></div>
    <?php else : ?>
      <div class="news-org-name"><?php print $org_name ?></div>
    <?php endif ; ?>
    <div class="news-clip-date">
      <?php print $date ?> 
    </div>
  </div><!-- /news-clip-banner -->

  <div class="news-clip-headline"><?php print $headline ?></div>
  <?php if ($subhead) : ?>
    <div class="news-clip-subhead"><?php print $subhead ?></div>
  <?php endif ?>

  <div class="news-clip-by-line clear-block">
    <?php if ($by) { ?>
      <div class='news-clip-author'>By <?php print $by ?></div> 
    <?php } elseif ($author) {
        $count = 0;
        foreach ($author as $name) {
          if (strlen($name) != 0) {
            $count++;
            $by = ($count == 1) ? 'By' : 'and';
            print "<div class='news-clip-by'>$by&nbsp;</div><div class='news-clip-author'>$name&nbsp;</div>";
          }
        }
      }
    ?>
  </div>

</div><!-- /news-clip-header -->
