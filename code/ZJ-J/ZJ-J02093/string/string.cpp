#include<bits/stdc++.h>
using namespace std;
long long n,ans,ans1;
int a;
char b;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		ans+=a;
		for(int j=1;j<=a;j++)s+=b;
	}
	for(int i=0;i<ans/2;i++){
		int j=ans-i-1;
		if(s[i]!=s[j])ans1++;
	}cout<<ans1;
}