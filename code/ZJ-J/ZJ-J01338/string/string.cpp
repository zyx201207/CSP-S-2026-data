#include<bits/stdc++.h>
using namespace std;
long long n;
long long p,q,ans;
long long s[200001];
char c[200001];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>c[i];
	}
	p=1,q=n;
	while(p<=q){
		if(p==q) break;
		if(c[p]!=c[q]){
			ans=ans+min(s[p],s[q]);
		}
		if(s[p]>s[q]){
			s[p]-=s[q];
			s[q]=0;
			q--;
		}
		else if(s[p]<s[q]){
			s[q]-=s[p];
			s[p]=0;
			p++;
		}
		else if(s[p]==s[q]) p++,q--;
	}
	cout<<ans;
	return 0;
}