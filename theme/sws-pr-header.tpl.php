<?
// $Id$

/**
 * @file sws-pr-header.tpl.php
 * Default theme implementation to display press release header. 
 *
 * Available variables:
 * - $node: The node object.
 * - $org (name of organization putting out press release, e.g. The White House)
 * - $dept (name of department putting out press release, e.g. Office of the Press Secretary)
 * - $headline
 * - $subhead
 * - $status (e.g. For immediate release or Embargoed until)
 * - $date 
 * - $contact, array of strings (e.g. $contact[0] = "John Doe, 555 555 5555")
 * 
 * @see template_preprocess_sws_pr_header()
 */
?>
<div class="pr-organization"><?php print $org ?></div>
<div class="pr-department"><?php print $dept ?></div>
<div class="dateline-container clear-block">
  <div class="dateline">
    <div class="date">
      <div class="pr-status"><?php print $status ?></div>
      <div class="pr-date"><?php print $date ?></div>
    </div>
  <?php if ($contact) : ?>
    <div class="contacts">
      <div class="pr-contact-label">Contact</div>
        <?php foreach ($contact as $num => $contact) { print 
        "<div class='pr-contact pr-contact-$num'>$contact</div>"; } ?>
    </div>
  <?php endif; ?>
  </div><!-- /dateline -->
</div>
<div class="pr-headline"><?php print $headline ?></div> 
<div class="pr-subhead"><?php print $subhead ?></div>
