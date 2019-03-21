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
  s.summary = "A short description of InternalWeChatSDK."

  # This description is used to generate tags and improve search results.
  #   * Think: What does it do? Why did you write it? What is the focus?
  #   * Try to keep it short, snappy and to the point.
  #   * Write the description between the DESC delimiters below.
  #   * Finally, don't worry about the indent, CocoaPods strips it!
  s.description = <<-DESC
                   DESC

  s.license = "Internal Use Only"

  s.author = {"Hovhannes Safaryan" => "hov@picsart.com"}
  s.platform = :ios

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
