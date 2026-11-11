#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	string s1={0};
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		if(i==1){
			s1=c;
			a--;
			}
		for(int j=1;j<=a;j++) s1+=c;
	}
	int ls=s1.size(),hw=ls-1;
	for(int i=0;i<ls/2;i++){
		if(s1[hw]!=s1[i]) ans++;
		hw--;
	}
	cout<<ans<<endl;
	return 0;
}
