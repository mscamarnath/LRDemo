vuser_init()
{
	//This is my second commit
	
web_set_sockets_option("SSL_VERSION", "TLS1.2");
	web_set_max_html_param_len("99999999");
	web_reg_save_param("c_RequestId","LB=input type=\"hidden\" value=\"","RB=\" name=\"request_id",LAST);
	
	lr_start_transaction("TC01_BasicMapUse_MultiPort_T00_LaunchURL");
	
	web_custom_request("ppd.advantagepoint.guycarp.com", 
		"URL=https://ppd.advantagepoint.guycarp.com/", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_start(NULL);

	web_custom_request("GCPortalStyleBlue.css", 
		"URL=https://ssoppd.guycarp.com/gcsso/resources/css/GCPortalStyleBlue.css", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://ssoppd.guycarp.com/Login.GC?contextType=external&username=string&initial_command=none&OverrideRetryLimit=0&contextValue=%2Foam&MaxPreservedPostDataBytes=5000000&password=sercure_string&challenge_url=https%3A%2F%2Fssoppd.guycarp.com%2FLogin.GC&request_id={c_RequestId}&authn_try_count=0&locale=en_US&resource_url=https%253A%252F%252Fppd.advantagepoint.guycarp.com%252F", 
		"Snapshot=t2.inf", 
		LAST);

	web_custom_request("GCPortalStyleExtBlue.css", 
		"URL=https://ssoppd.guycarp.com/gcsso/resources/css/GCPortalStyleExtBlue.css", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://ssoppd.guycarp.com/Login.GC?contextType=external&username=string&initial_command=none&OverrideRetryLimit=0&contextValue=%2Foam&MaxPreservedPostDataBytes=5000000&password=sercure_string&challenge_url=https%3A%2F%2Fssoppd.guycarp.com%2FLogin.GC&request_id={c_RequestId}&authn_try_count=0&locale=en_US&resource_url=https%253A%252F%252Fppd.advantagepoint.guycarp.com%252F", 
		"Snapshot=t3.inf", 
		LAST);

	

	web_concurrent_end(NULL);

	
	return 0;
}
