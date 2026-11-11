#include<bits/stdc++.h>
using namespace std;
int a[71]={};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	a[65]=a[66]=a[67]=1;
	a[68]=a[70]=2;
//	int T;
//	cin>>T;
//	while(T--){
	int a1,a2;
	string s1,s2;
	cin>>a1>>s1>>a2>>s2;
	if(a1==a2){
		if(s1.substr(0,2)==s2.substr(0,2)){
			if(a[s1[2]]==a[s2[2]]){
				if(abs(s1[2]-s2[2])==1||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
					cout<<"1111";
				}else cout<<"1110";
			}else cout<<"1100";
		}else cout<<"1000";
	}else cout<<"0000";
//	cout<<endl;
//	}
	return 0;
}

