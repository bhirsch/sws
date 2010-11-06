<?
// $Id$

/**
 * @file sws-newsclip-footer.tpl.php
 * Default theme implementation to display news clip footer.
 *
 * Available variables:
 * - $footer (defined by user)
 * 
 * @see template_preprocess_sws_newsclip_footer()
 */
?>
<?php if ($footer) : ?>
  <div class="news-clip-footer"><?php print $footer ;?></div>
<?php endif; ?>
