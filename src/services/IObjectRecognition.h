/**
* Copyright 2017 IBM Corp. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
*/


#ifndef SELF_IOBJECT_RECOGNITION_H
#define SELF_IOBJECT_RECOGNITION_H

#include "utils/IService.h"
#include "SelfLib.h"		// include last always

//! Visual recognition service interface
class SELF_API IObjectRecognition : public IService
{
public:
	RTTI_DECL();

	//! Types
	typedef Delegate<const Json::Value &>	OnClassifyObjects;

	//! Construction 
	IObjectRecognition( const std::string & a_ServiceId, AuthType a_AuthType = AUTH_BASIC ) 
		: IService( a_ServiceId, a_AuthType )
	{}

	//! Classify the given depth image data and return all objects found in the field of view
	//! This function should return the following JSON:
	/*
	{ "objects" : [
		{ 
			"objectId" : "drill",
			"confidence" : 0.9,
			"transform" : [ 5.0, 3.0, 1.0 ],
			"rotation" : [ 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 ]
		}
	] }
	*/
	virtual void ClassifyObjects(const std::string & a_DepthImageData,
		OnClassifyObjects a_Callback ) = 0;
};

#endif
