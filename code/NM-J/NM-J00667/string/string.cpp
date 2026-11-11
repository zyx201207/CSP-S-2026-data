#include<bits/stdc++.h>
using namespace std;
string s[200000000000000005];
string x;
long long b,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int y=n;
	while(y--){
		cin>>b>>x;
		while(b--){
			s[++ans]=x;
		}
	}
	ans=0;
	for(int i=1;i<=n/2;i++){
		for(int j=n;j<=n/2;j--){
			if(s[i]!=s[j])ans++;
		}
	}
	cout<<ans;
	return 0;
}
