#include<bits/stdc++.h>
using namespace std;
const int N=2E5+5;
int len[N];
char kzf[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>len[i]>>kzf[i];
	}
	long long pre=0,nxt=0;
	char pn,nn;
	int l=0,r=n+1;
	long long ans=0;
	while (l<r){
		int tot=min(pre,nxt);
		pre-=tot;
		nxt-=tot;
		if (pn!=nn){
			ans+=tot;
		}
		if (pre==0){
			pre=len[++l];
			pn=kzf[l];
		}
		if (nxt==0){
			nxt=len[--r];
			nn=kzf[r];
		}
	}
	cout<<ans;
	return 0;
}
