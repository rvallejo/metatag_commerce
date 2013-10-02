<?php


//
// Implements hook_metatag_config_default_alter().
//
function metatag_commerce_metatag_config_default_alter(array &$configs) {
  foreach ($configs as &$config) {
    switch ($config->instance) {
      case 'global':
        $config->config += array();
        break;
 
      case 'global:frontpage':
        $config->config += array();
        break;
 
      case 'node':
        $config->config += array(
          'og:price:amount' => array('value' => '[node:field-products:0:commerce-price:amount_decimal]'),
          'og:price:currency' => array('value' => '[node:field-products:0:commerce-price:currency_code]'),
          'og:availability' => array('value' => ''),
          'og:brand' => array('value' => ''),
          'og:upc' => array('value' => '[node:field-products:0:sku]'),
          'og:ean' => array('value' => ''),
          'og:isbn' => array('value' => ''),
        );
        break;
 
      case 'taxonomy_term':
        $config->config += array();
        break;
 
      case 'user':
        $config->config += array( );
        break;
    }
  }
}

/**
 * Implements hook_metatag_info().
 */
function metatag_commerce_metatag_info() {

  $info['groups']['metatag_commerce'] = array(
    'label' => t('Commerce Metatags'),
	'form' => array(
		'#weight' => 51,
	)
  );

	  $info['tags']['og:price:amount'] = array(
		'label' => t('Open Graph Price'),
		'description' => 'Product price (without currency sign, for example "6.50")',
		'class' => 'DrupalTextMetaTag',
		'group' => 'metatag_commerce',
	  );
	  $info['tags']['og:price:currency'] = array(
		'label' => t('Open Graph Currency'),
		'description' => 'Currency code string as defined in http://www.xe.com/iso4217.php (for example "USD")',
		'class' => 'DrupalTextMetaTag',
		'group' => 'metatag_commerce',
	  );
	  $info['tags']['og:availability'] = array(
		'label' => t('Open Graph Availability'),
		'description' => 'Case insensitive string, possible values: "in stock", "instock", "preorder", "backorder", "pending", "out of stock", "oos", "discontinued".',
		'class' => 'DrupalTextMetaTag',
		'group' => 'metatag_commerce',
	  );
	  $info['tags']['og:brand'] = array(
		'label' => t('Open Graph Brand'),
		'description' => '',
		'class' => 'DrupalTextMetaTag',
		'group' => 'metatag_commerce',
	  );
	  $info['tags']['og:upc'] = array(
		'label' => t('Open Graph UPC'),
		'description' => '',
		'class' => 'DrupalTextMetaTag',
		'group' => 'metatag_commerce',
	  );
	  $info['tags']['og:ean'] = array(
		'label' => t('Open Graph EAN'),
		'description' => '',
		'class' => 'DrupalTextMetaTag',
		'group' => 'metatag_commerce',
	  );
	  $info['tags']['og:isbn'] = array(
		'label' => t('Open Graph ISBN'),
		'description' => '',
		'class' => 'DrupalTextMetaTag',
		'group' => 'metatag_commerce',
	  );
	
	return $info;
}