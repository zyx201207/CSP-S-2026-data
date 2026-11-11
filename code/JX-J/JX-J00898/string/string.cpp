#include<bits/stdc++.h>
using namespace std;

long long n,a,ans,cnt=0;
string s,w;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>w;
		for(int j=0;j<a;j++)s+=w;
	}
	cnt=s.size();
	int t=cnt-1;
	for(int i=0;i<cnt/2;i++,t--){
		if(s[i]!=s[t])ans++;
	}
	cout<<ans;
	return 0;
}
