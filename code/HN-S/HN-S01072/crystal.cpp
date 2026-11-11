#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
long long n,m;
int maxx=0;
long long a[maxn];
void check(int x){
	int cnt=1;
	int cost=0;
	int k[maxn];
	for(int i=1;i<=n;i++){
		k[i]=abs(a[x]-a[i]);
	}
	sort(k+1,k+1+n);
	
	for(int i=2;i<=n;i++){
		cost+=k[i];
		if(cost<=m)cnt++;
		else break;
	}
	
	maxx=max(maxx,cnt);

}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n;
	for(int i=1;i<=n;i++){
		check(i);
	}
	cout<<maxx;
	return 0;
} 
