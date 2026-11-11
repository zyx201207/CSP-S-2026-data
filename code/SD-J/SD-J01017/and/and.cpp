#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long t[10];
long long maxx=0;
long long flag=0;
long long d2;
bool cmp(long long a,long long b){
	return a>b;
}
void dfs(long long x,long long s,long long ans){
	if(s>m){
		maxx=max(maxx,ans);
		return ;
	}
	s++;
	for(int i=x+1;i<=n;i++){
		ans=(a[x]&a[i]);
		dfs(i,s,ans);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		flag=max(flag,a[i]);
	}
	d2=a[1];
	for(int i=1;i<=n;i++){
		d2=d2&a[i];
	}
	if(m==1){
		cout<<flag;
		return 0;
	}
	if(m==n){
		cout<<d2;
		return 0;
	}
	if(flag==4){
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			t[a[i]]++;
		}
		if(t[4]>=m){
			cout<<4;
			return 0;
		}else{
			maxx=a[n-t[4]+1];
			for(int i=n-t[4]+1;i<=m+n-t[4]+1;i++){
				maxx=maxx&a[i];
			}
			cout<<maxx;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		dfs(i,2,0);
	}
	cout<<maxx;
	return 0;
}
