#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],x[500010],y[500010],t,ss[500010],f[500010],b[500010],c[500010],d[500010];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ss[a[i]]+=i;
		if(y[a[i]]!=0){
			x[y[a[i]]]=i;
		}y[a[i]]=i;
	}for(int i=1;i<=n;i++){
		if(x[i]!=0){
			f[i]=i-t;
			t=i;
		}
	}for(int i=n;i>=1;i--){
		if(x[i]!=0)b[i]=i;
		else b[i]=b[i+1];
	}for(int i=1;i<=n;i++){
		if(x[i]!=0){
			f[b[x[i]]]+=f[i];
			c[i]+=f[i];c[x[i]]-=f[i];
		}
	}for(int i=1;i<=n;i++){
		d[i]=d[i-1]+c[i];
		ss[a[i]]-=d[i];
	}
	for(int i=1;i<=m;i++){
		cout<<ss[i]<<' ';
	}
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1


#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000010],x[1000010],y[1000010],t,ss[1000010];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(y[a[i]]!=0){
			x[y[a[i]]]=i;
		}y[a[i]]=i;
	}for(int i=1;i<=n;i++){
		int t=0;
		for(int j=i;j<=n;j++){
			if(x[j]>x[t]&&j>=x[t])t=j;
			if(j>=x[t])ss[a[j]]++;
		}
	}for(int i=1;i<=m;i++){
		cout<<ss[i]<<' ';
	}
	return 0;
}



*/
