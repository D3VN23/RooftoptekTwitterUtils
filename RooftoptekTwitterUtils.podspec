Pod::Spec.new do |s|
  s.name        = 'RooftoptekTwitterUtils'
  s.version     = '0.0.1'
  s.summary     = 'Parse SDK for Apple platforms.'
  s.description = 'Parse SDK for Apple platforms.'
  s.authors     = 'Rooftoptek'
  s.homepage    = 'https://www.rooftoptek.com/'
  s.license     = { :type => 'BSD', :file => 'LICENSE' }
  s.source      = { :path => '../RooftoptekTwitterUtils' }

  s.platform = :ios
  s.requires_arc = true

  s.ios.deployment_target = '9.0'

  s.public_header_files = 'RooftoptekTwitterUtils/*.h'
  s.source_files = 'RooftoptekTwitterUtils/**/*.{h,m}'

  s.dependency 'Rooftop', '~> 0.0.1'
  s.dependency 'Fabric'
  s.dependency 'TwitterKit'

end
