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

  return system_settings_form($form);
} 
