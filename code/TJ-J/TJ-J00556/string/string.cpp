#include<bits/stdc++.h>
using namespace std;
long long zmaxn=-99,ymaxn=-99;
long long zt;
long long yt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="",ans="";
	int n;
	long long id=0;
	cin>>n;
	int flag=0;
	long long l=1,r,a,mid;
	char c;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		} 
	}
	r=s.size();
	for(int i=0;i<r-1;i++){
		if(s[i]!=s[i+1]){
			flag=1;
		}
	}
	if(flag==0){
		cout<<0;
		return 0;
	}
	flag=0;
	for(int i=r;i>0;i--){
		ans[id]=s[i];
		id++;
	}
	for(int i=0;i<r;i++){
		if(s[i]!=ans[i]) flag=1;
	}
	if(flag==0){
		cout<<0;
		return 0;
	}
	mid=(l+r)/2;
	for(int i=0;i<mid-1;i++){
		if(s[i]!=ans[i]) zt++;
	}
	for(int i=mid;i<r;i++){
		if(s[i]!=ans[i]) yt++;
	}
	cout<<max(yt,zt);
	return 0;
} 
