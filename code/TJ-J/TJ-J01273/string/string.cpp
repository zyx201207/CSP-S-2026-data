#include<bits/stdc++.h>
using namespace std;
long long n,m,nm,mn,ans,p=1,o;
string s,s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m>>s1[0];
		for(int j=mn;j<mn+m;j++){
			s[j]=s1[0];
		}
		mn+=m;
	}
	nm=mn;
	if(mn%2==2){
		mn/=2;
	}else{
		mn/=2;
		mn++;
	}
	for(int i=0;i<mn;i++){
		if(s[i]!=s[nm-1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
