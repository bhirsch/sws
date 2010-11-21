<?php
// $Id$

/**
 * @file
 * administration page callbacks for sws module
 */

/**
 * Form builder. Configure sws settings.
 *
 * @ingroup forms
 * @see system_settings_form().
 */
function sws_admin_settings() { 
  // Website footer
  $form['footer'] = array(
    '#type' => 'fieldset',
    '#title' => 'Website Footer',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['footer']['sws_site_footer'] = array( 
    '#type' => 'textarea',
    '#title' => t('Footer'),
    '#description' => t('This footer will appear at the very bottom of the website on every page.'), 
    '#default_value' => variable_get('sws_site_footer', NULL),
  ); 
  // News Clip settings
  $form['newsclip'] = array(
    '#type' => 'fieldset',
    '#title' => 'News Clip Footer',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['newsclip']['sws_news_clip_footer'] = array( 
    '#type' => 'textarea',
    '#title' => t('Footer'),
    '#description' => t('Some people post whole, copyrighted '
                       .'articles on their own websites ' 
                       .'along with a "fair use notice" at the bottom '
                       .'of the article. You can put a notice, or '
                       .'any other disclaimer, explanation, or custom '
                       .'footer text here. NOTE: This is '
                       .'not legal advise. Re-use copyrighted material '
                       .'at your own risk. Here is an example of a fair '
                       .'use notice: <br/><br/>'
                       .'FAIR USE NOTICE <br/> This site contains copyrighted material the use of which has not always been specifically authorized by the copyright owner. In accordance with Title 17 U.S.C. Section 107, the material on this site is available without profit for research and educational purposes. If you wish to use copyrighted material from this site for purposes of your own that go beyond "fair use", you must obtain permission from the copyright owner. '), 
    '#default_value' => variable_get('sws_news_clip_footer', NULL),
  ); 

  // Press Release settings
  $form['pr'] = array(
    '#type' => 'fieldset',
    '#title' => 'Press Release Settings',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['pr']['sws_pr_header'] = array( 
    '#type' => 'textfield',
    '#title' => t('Header'),
    '#description' => t('This will be displayed at the top '
                       .'of every press release. ' 
                       .'E.g. "The White House"'), 
    '#default_value' => variable_get('sws_pr_header', variable_get('site_name', NULL)),
  ); 
  $form['pr']['sws_pr_subhead'] = array( 
    '#type' => 'textfield',
    '#title' => t('Subhead'),
    '#description' => t('Displayed at the top '
                       .'of press releases below the header. ' 
                       .'E.g. "Office of the Press Secretary"'), 
    '#default_value' => variable_get('sws_pr_subhead', NULL),
  ); 
  $form['pr']['sws_pr_footer'] = array( 
    '#type' => 'textarea',
    '#title' => t('Footer'),
    '#description' => t('Displayed in the footer of every press release. '
                       .'For example, you might put something like: "'
                       .'Sonia Chang-Diaz is the state senator for '
                       .'Massachusetts Second Suffolk District. Her '
                       .'district includes Roxbury, Jamaica Plain, the '
                       .'South End, Chinatown, Back Bay, Mission Hill, '
                       .'Beacon Hill, Dorchester and Mattapan."'), 
    '#default_value' => variable_get('sws_pr_footer', NULL),
  ); 

  return system_settings_form($form);
} 