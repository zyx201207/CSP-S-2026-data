#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2*1e5+10;
int n,m;
int a[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int k=0;k<=(1<<n);k++){
		int z=k;
		int cnt=0;
		while(z){
			if(z&1){
				cnt++;
			}
			z>>=1;
		}
		z=k;
		int num=0;
		if(cnt==m){
			for(int i=1;i<=n;i++){
				if(z&1){
					if(num==0) num=a[i];
					else num=(num&a[i]);
				}
				z>>=1;
			}
			ans=max(ans,num);
		}
	} 
	cout<<ans;
	return 0;
}

