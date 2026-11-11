#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	int len1=s1.size();
	int len2=s2.size();
	string t,tt;
	for(int i=0;i<len1-1;i++){
		t=t+s1[i];
	}
	for(int i=0;i<len2-1;i++){
		tt=tt+s2[i];
	}
	if(t==tt){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(s1[len1-1]=='A' || s1[len1-1]=='B' || s1[len2-1]=='C'){
		if(s2[len2-1]=='A' || s2[len2-1]=='B' || s2[len2-1]=='C'){
			cout<<1;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	else{
		if(s2[len2-1]=='D' || s2[len2-1]=='F'){
			cout<<1;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	if(s1[len1-1]-1==s2[len2-1] || s1[len1-1]+1==s2[len2-1]){
		cout<<1;
	}
	else{
		cout<<"0";
	}
	return 0;
}
