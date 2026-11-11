#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=5e5+10,M=3e5+10;
long long a[N],b[N];
int cnt[M];
bool flag=true;
int main(){//Write until 11a.m.   11:15
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(i>1 && a[i]<a[i-1])flag=false;
	}
	if(m==1){
		cout<<n<<'\n';
		return 0;
	}
	if(flag){
		map<int,bool> p;
		p.clear();
		for(int i=1;i<=n;++i){
			for(int j=i;j<=n;++j){
				if(p[a[j]]==0)cnt[a[j]]++,p[a[j]]=true;
			}
			p.clear();
		}
		for(int i=1;i<=m;++i)cout<<cnt[i]<<'\n';
		return 0;
	}
	for(int i=1;i<=n;++i){
		long long tot=0;
		for(int j=i;j<=n;++j){
			tot++;
			b[tot]=a[j];
		}
		for(int k=1;k<=tot;++k){
			int x=0;
			for(int j=k-1;j>=1;--j){
				if(b[j]==b[k]){
					x=j;
					break;
				}
			}
			if(x!=0){
				for(int j=x;j<=k-1;++j)b[j]=-1;
			}
		}
		for(int k=1;k<=tot;++k){
			if(b[k]!=-1)cnt[b[k]]++;
		}
	}
	for(int i=1;i<=m;++i){
		cout<<cnt[i]<<' ';
	}
	cout<<'\n';
	return 0;
}
/*
4 3
1 2 1 3
10 3
3 1 2 1 3 2 3 1 2 1
*/
