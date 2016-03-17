<?php
// 페이지 로딩 전 사전 작업
include_once "preload.php";
// test comment
?>

<!DOCTYPE html>
<html>
<head>
	<title>Javascript study</title>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<link rel="stylesheet" href="http://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css">
	<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.0/jquery.min.js"></script>
	<script src="http://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/js/bootstrap.min.js"></script>

	<style>
		@import url(http://fonts.googleapis.com/earlyaccess/notosanskr.css);
		@import url(http://fonts.googleapis.com/earlyaccess/notosansjp.css);
		@import url(http://fonts.googleapis.com/earlyaccess/notosanssc.css);
		/*  한국어 
 		*  이것을 사용할 경우 bootstrap에서 glyphicon이 나타나지 않음.
		:lang(ko) {
		  font-family: 'Noto Sans KR', '굴림체', sans-serif;
		}
		*/
		 /* 일본어 */
		:lang(ja) {
		  font-family: 'Noto Sans JP', sans-serif;
		}
		 /* 중국어 (간체) */
		:lang(zh-Hans) {
		  font-family: 'Noto Sans SC', sans-serif;
		}
	</style>

	<script type="text/javascript">
		// 자체 라이브러리
		var study = {};
		var studyItems = function(initItems) {
			var items = initItems;

			return {
				addItem : function(obj) {
					if(typeof obj !== "object") {
						console.write("addItem : parameter error");
						return;
					}
					if(typeof obj[title] === "undefined" || typeof obj[link] === "undefined") {
						console.write("addItem : parameter error2");
						return;
					}
				},
				delItem : function(key) {
				},
				itemUpdate : function() {
				}
			};	
		}();
	</script>

</head>

<body lang="<?=$lang?>" style="font-size:'<?=$config['default_font_size']?>'">
	
<?php 

	// 페이지 상단 
	include_once "header.php"; 
	// 메뉴 
	include_once "menu.php"; 

	switch($page) {
		case "js" : 
		case "vim" : 
		case "bs" : 
		case "ng" : 
		case "php" : include "page_common.php"; break;
		case "html" : include "page_html.php"; break;
		case "login" : include "page_login.php"; break;
		case "logout" : include "page_logout.php"; break;
		default : include "page_home.php";
	}

	// 페이지 하단
	include_once "footer.php"; 
?>

</body>
</html>
