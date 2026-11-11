#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=0x3f3f3f3f;
const int inff=0x3f3f3f3f3f3f3f3f;
const int N=1e6+5;
const int M=1005;
const int mod=1e9+7;
int n,a[N],m,b[N];
bool check(int i,int mid){
	if((i-mid+1)*b[i]-(a[i]-a[mid-1])<=m){
//		cout<<(i-mid+1)*b[i]-(a[i]-a[mid-1])<<'\n';
		return 1;
	}
	return 0;
}
void fast(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	fast();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i];
		a[i]+=a[i-1];
	}
	int maxx=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r-1){
			int mid=(l+r)>>1;
			if(check(i,mid)){
				r=mid;
			}
			else{
				l=mid;
			}
		}
		if(check(i,l)){
			maxx=max(maxx,i-l+1);
		}
		else{
			maxx=max(maxx,i-r+1);
		}
//		cout<<l<<' '<<r<<' '<<i<<'\n';
	}
	cout<<maxx;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=0x3f3f3f3f;
const int inff=0x3f3f3f3f3f3f3f3f;
const int N=1e6+5;
const int M=1005;
const int mod=1e9+7;

void fast(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	fast();

	return 0;
}

