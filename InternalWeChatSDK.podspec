#
#  Be sure to run `pod spec lint InternalWeChatSDK.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|
  s.name = "InternalWeChatSDK"
  s.version = "0.0.2"
  s.summary = "Internal redistribution of WeChat SDK, InternalWeChatSDK."
  s.description = <<-DESC
  There is not official WeChatSDK CocoaPods distribution.
  We used to push binary files into the repo, now we have moved
  all binaries to our Nexus repo or to CocoaPods, Nexus is preferred.
                   DESC

  s.license = "Internal Use Only"

  s.author = {"Hovhannes Safaryan" => "hov@picsart.com"}
  s.platform = :ios
  s.homepage = "https://open.wechat.com/cgi-bin/newreadtemplate?t=overseas_open/docs/mobile/getting-started/ios"

  # ――― Source Location ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  Specify the location from where the source should be retrieved.
  #  Supports git, hg, bzr, svn and HTTP.
  #

  s.source = {:git => "https://github.com/hovox/WeChatSDKPod.git", :tag => "#{s.version}"}

  s.source_files = "Headers/*.h"
  s.vendored_libraries = "libWeChatSDK.a"

  s.requires_arc = true
end
