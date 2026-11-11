#include<bits/stdc++.h>
using namespace std;
struct node{
	long long l,r;
	char c;
}s[200005];
int n;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long len=0;
	long long ll;
	char ch;
	for(int i=1;i<=n;i++){
		cin>>ll;
		cin>>ch;
		s[i].l=len+1;
		s[i].r=len+ll;
		s[i].c=ch;
		len+=ll;
	}
	int j=n;
	long long ans=0;
	for(int i=1;s[i].l<=len/2;i++){
		long long nowl=s[i].l;
		long long nowr=s[i].r;
		while(len+1-s[j].l<=nowr&&i<j){
			if(s[j].c!=s[i].c){
				ans+=min(s[j].r-s[j].l+1,len+2-s[j].l-nowl);
			}
			j--;
		}
		if(s[j].c!=s[i].c){
			ans+=min(nowr-nowl+1,nowr-len+s[j].r);
		}
	}
	cout<<ans;
	return 0;
}