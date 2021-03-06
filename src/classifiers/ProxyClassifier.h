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


#ifndef SELF_PROXY_CLASSIFIER_H
#define SELF_PROXY_CLASSIFIER_H

#include "IClassifier.h"
#include "SelfLib.h"

//! This classifier class is used to represent a remote classifier that is running outside this self instance
class SELF_API ProxyClassifier : public IClassifier
{
public:
	RTTI_DECL();

	//! Types
	typedef boost::shared_ptr< ProxyClassifier >		SP;
	typedef boost::weak_ptr< ProxyClassifier >		WP;

	//! Construction
	ProxyClassifier(const std::string & a_ClassifierName, 
		const std::string & a_InstanceId,
		bool a_bOverride,
		const std::string & a_Origin);

	ProxyClassifier();
	~ProxyClassifier();

	//! ISerializable interface
	virtual void Serialize(Json::Value & json);
	virtual void Deserialize(const Json::Value & json);

	//! IClassifier interface	
	virtual const char * GetName() const;
	virtual bool OnStart();
	virtual bool OnStop();

	void SendEvent(const std::string & a_EventName);

	const std::string & GetOrigin() const
	{
		return m_Origin;
	}

	const std::string & GetClassifierName() const
	{
		return m_ClassifierName;
	}


protected:
	//! Data
	std::string			m_Origin;
	std::string			m_ClassifierName;
	bool				m_bOverride;
};

#endif // SELF_PROXY_CLASSIFIER_H
