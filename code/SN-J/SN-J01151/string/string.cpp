#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
struct node{
	int s;
	char c;
}mp[200001];
int ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>mp[i].s>>mp[i].c;
	}
	for(int l=1,r=n;l<r;){
		int mi=min(mp[l].s,mp[r].s);
		mp[l].s-=mi,mp[r].s-=mi;
		if(mp[l].c!=mp[r].c)ans+=mi;
		if(!mp[l].s)l++;
		if(!mp[r].s)r--;
	}
	cout<<ans;
	return 0;
}
