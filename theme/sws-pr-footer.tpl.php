<?
// $Id$

/**
 * @file sws-pr-footer.tpl.php
 * Default theme implementation to display press release footer.
 *
 * Available variables:
 * - $footer (defined by user)
 * 
 * @see template_preprocess_sws_newsclip_footer()
 */
?>
<?php if ($footer) : ?>
  <div class="pr-footer"><?php print $footer ;?></div>
<?php endif; ?>
