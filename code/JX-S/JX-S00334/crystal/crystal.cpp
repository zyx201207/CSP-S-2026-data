#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],m;
int n,maxx,ans;
map<long long,int> mp;

void dfs(long long num,int pos){
	if(num==m){
		ans=max(ans,maxx);
		return;
	}
	if(pos==n+1){
		ans=max(ans,maxx);
		return;
	}
	for(int i=1;i<=m-num;++i){
		mp[a[pos]]--;
		mp[a[pos]+i]++;
		int ma=maxx;
		maxx=max(maxx,mp[a[pos]+i]);
		dfs(num+i,pos+1);
		mp[a[pos]]++;
		mp[a[pos]+i]--;
		maxx=ma;
	}
	dfs(num,pos+1);
}


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool ye=1,yy=1;
	long long ca=0;
	for(int i=1;i<=n;++i){
		if(i>=2) ca=a[i]-a[i-1];
		cin>>a[i];
		if(a[i]!=i) ye=0;
		if(i>=3&&a[i-1]+ca!=a[i]) yy=0;
		mp[a[i]]++;
	}
	if(ye){
		for(int i=1;m-i>=0;i++) m-=i,ans++;
	}else if(yy){
		for(int i=ca;m-i>=0;i+=ca) m-=i,ans++;
	}else{
		dfs(0,1);
	}
	cout<<ans;
	return 0;
}
