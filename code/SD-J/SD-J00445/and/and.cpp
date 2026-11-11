#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fr front
#define fi first
#define se second
#define i64 long long
const int N=2e5+5;
const int inf=0x3f3f3f3f;
int n,m;
int a[N];
int ans;
int maxx=-inf;
i64 b[35];
int anss=-inf;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    b[1]=2;
    for(int i=2;i<=30;i++){
    	b[i]=b[i-1]*2*1LL;
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			for(int k=1;k<=n&&k!=i;k++){
				anss=max(anss,a[k]&a[i]);
			}
		}
	}
	cout<<anss;
	return 0;
}
