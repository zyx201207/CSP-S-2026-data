#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxx=5e5+10;
const int maxn=1e12;
int n,m;
int a[maxx],ans,minn=1e18;
int s[maxx];
bool check(int x){
	int num=0;
	for(int i=1;i<=n;i++){
		if(a[i]>x) break;
		num=num+(x-a[i]);
	}
	return num<=m;
} 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=-maxn-1,r=maxn+1;
	int x=abs(minn);
	if(minn<0){
		l=100,r=maxn+1+x;
		for(int i=1;i<=n;i++){
			a[i]+=x;
		}
	}
	sort(a+1,a+1+n);
	while(l+1<r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid;
		}
		else r=mid;
//		cout<<"mid:"<<mid<<" l:"<<l<<" r:"<<r<<"\n";
	}
//	cout<<l;
	for(int i=1;i<=n;i++){
		if(a[i]<=l) ans++;
	}
	cout<<ans;
	return 0;
}

