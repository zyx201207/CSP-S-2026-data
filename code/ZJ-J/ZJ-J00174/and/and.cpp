#include<bits/stdc++.h>
#define int long long
using namespace std;
string a[200010];
string vis[200010];
string nw[200010];
map<int,int> mp;
int n,m,maxl,last,visn,nwn,ans;
string zh(int x){
	string ans="";
	while(x){
//		cout<<x<<'\n';
		int t=x%2;
		if(t==0)  ans='0'+ans;
		else  ans='1'+ans;
//		cout<<char(x%2-'0')<<'\n';
		x/=2;
	}
	return ans;
}
string bq(int l,string x){
	string ans=x;
	for(int i=1;i<=l-x.size();i++)
		ans='0'+ans;
	return ans;
}
bool cmp(string x,string y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i]=zh(x);
		int t=a[i].size();
		maxl=max(maxl,t);
	}
	for(int i=1;i<=n;i++)
		if(a[i].size()!=maxl)
			a[i]=bq(maxl,a[i]);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++)
		nw[++nwn]=a[i];
	for(int i=0;i<a[m].size();i++){
		if(a[m][i]=='0')  break;
		last++;
		ans=ans+pow(2,a[m].size()-i-1);
//		cout<<a[m].size()-i-1<<' ';
	}
//	cout<<ans<<'\n';
	for(int i=m+1;i<=n;i++){
		int j;
		for(j=0;j<last;j++)
			if(a[i][j]=='0')
				break;
		if(j!=last)  break;
		nw[++nwn]=a[i];
	}
//	cout<<last<<'\n';
	while(last<=maxl){
		int x=maxl;
		for(int i=1;i<=nwn;i++)
			for(int j=0;j<nw[i].size();j++)
				if(nw[i][j]=='1')  mp[j]++;
		for(int i=last;i<maxl;i++)
			if(mp[i]>=m){
				x=i;
				break;
			}
		if(x==maxl)  break;
		last=x+1;
		for(int i=1;i<=nwn;i++)
			if(nw[i][x]=='1')
				vis[++visn]=nw[i];
		for(int i=0;i<nw[0].size();i++)
			mp[i]=0;
		if(visn<m)  break;
		ans+=pow(2,maxl-x-1);
		nwn=visn;
		for(int i=1;i<=nwn;i++)
			nw[i]=vis[i],vis[i]="";
		visn=0;
	}
	cout<<ans;
	return 0;
}
/*
4 2 12 12 15 3
*/
