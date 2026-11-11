#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
const int INF=1024*1024*16-1;
int a[N],v1[N];
int ans;
ll dp[N];
map <int,int> v;
int n,m;

int b[N];
void f(int k,int s,int last){
	if(s<ans)
		return ;
	if(k==m){
		ans=max(ans,s);
		return ;
	}
	for(int i=last;i<=n;i++){
		if(!v1[i]){
			v1[i]=1;
			f(k+1,s&a[i],i+1);
			v1[i]=0;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int re=1;
	for(int i=1;i<=25;i++){
		v[re-1]=1;
		re*=2;
	}
	int flaga=0,flagb=0,maxn=0;
	
	cin>>n>>m;
	int sum=INF;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(v[a[i]])
			flaga++;
		if(a[i]==i-1)
			flagb++;
		maxn=max(maxn,a[i]);
		sum&=a[i];
	}
	if(m==n){
		cout<<sum;
		return 0;
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	
	if(flaga==n){
		cout<<a[n-m+1];
		return 0;
	}
	
	f(0,INF,0);
	cout<<ans;
	return 0;
}
/*
4 2
3 15 12 12
5 3
31 3 1 15 7
5 3
0 1 3 7 15
*/
