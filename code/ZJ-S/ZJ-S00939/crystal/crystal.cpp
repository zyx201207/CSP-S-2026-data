#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],ma=1,b[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=a[i]+b[i-1];
	int l=1;
	for(int i=2;i<=n;i++){
		int x=0;
		//int x=a[i]*(i-l+1)-(b[i]-b[l-1]);
		while(l<=i){
			x=a[i]*(i-l+1)-(b[i]-b[l-1]);
			if(x>m)l++;
			else break;
		}
		ma=max(ma,i-l+1);
	}
	cout<<ma;
}
