#include<bits/stdc++.h>
using namespace std;
string ticket[5];
string tmp1,tmp2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s;
	for(int i=1;i<=4;i++)
	{
		cin>>s;
		ticket[i]=s;
	}
  	//s1 R³µÏáºÅ s2 R×ùÎ»ºÅ
  	string ans;
	if(ticket[1]==ticket[3]) ans="1";
	else ans="0";
	if(ans[ans.size()-1]=='0') ans=ans+"0";
	else{
		for(int i=0;i<=1;i++)
		{
			tmp1=tmp1+ticket[2][i];
			tmp2=tmp2+ticket[4][i];
		}
		if(tmp1==tmp2){
			ans=ans+"1";
		}
		else ans=ans+"0";
	}
	if(ans[ans.size()-1]=='0') ans=ans+"0";
	else{
		string solve1="ABC";
		string solve2="DF";
		int cnt=0;
		for(int i=0;i<solve1.size();i++){
			if(ticket[2][2]==solve1[i]||ticket[4][2]==solve1[i]) cnt++;
		}
		if(cnt==2) ans=ans+"1";
		else{
			cnt=0;
			for(int i=0;i<solve2.size();i++){
				if(ticket[2][2]==solve2[i]||ticket[4][2]==solve2[i]) cnt++;
			}
			if(cnt==2) ans=ans+"1";
			else ans=ans+"0";
		}
	}
	if(ans[ans.size()-1]=='0') ans=ans+"0";
	else{
		if(ticket[2][2]=='D'||ticket[4][2]=='D'){
			if(abs(ticket[2][2]-ticket[4][2])==2) ans=ans+"1";
			else ans=ans+"0";
		}
		else{
			if(abs(ticket[2][2]-ticket[4][2])==1) ans=ans+"1";
			else ans=ans+"0";
		}
	}
	cout<<ans;
	return 0;
}
