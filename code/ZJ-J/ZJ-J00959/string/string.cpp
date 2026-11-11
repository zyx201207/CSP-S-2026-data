#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,v=1,ans=0;
	char b;
	cin>>n;
	string s[100000];
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			s[v+j]+=b;
		}
		v+=a;
	}	
	for(int i=1;i<=v/2;i++)
		if(s[i]!=s[v-i+1])
			ans++;
	cout<<ans;
	return 0;
}
