<?php
/**
 * @file
 * The field node link views handler for fasttoggle.
 *
 * This file defines the Views handler for rendering fasttoggle links.
 */
class fasttoggle_node_views_handler_field_node_link extends views_handler_field_node_link {
  var $fasttoggle_key = 'status';

  function construct() {
    parent::construct();

    if (isset($this->definition['fasttoggle_node']) && isset($this->definition['fasttoggle_node']['key'])) {
      $this->fasttoggle_key = $this->definition['fasttoggle_node']['key'];
    }
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    unset($form['text']);
  }

  function render($values) {
    if ($entity = $this->get_value($values)) {
      return $this->render_link($entity, $values);
    }
  }

  function render_link($node, $values) {
    if (!node_access('update', $node)) {
      return '';
    }

    drupal_load('module', 'fasttoggle');

    // Now we set the status to the actual value so that we get the
    // correct labels.
    $options = fasttoggle_get_allowed_links('node', $node, $node->nid, 'fasttoggle_togglable_options');
    $key = $this->fasttoggle_key;

    if (!empty($options['fields']['status']['instances'][$key])) {
      $link_info = fasttoggle($options, 'status', $key, $node, FASTTOGGLE_FORMAT_LINK_ARRAY);
      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = $link_info['href'];
      $this->options['alter']['text'] = $link_info['title'];
      $this->options['alter']['query'] = $link_info['query'];
      $this->options['alter']['link_class'] = implode(' ', $link_info['attributes']['class']);
      $this->options['alter']['title'] = $link_info['attributes']['title'];

      return $link_info['title'];

    }
  }
}
