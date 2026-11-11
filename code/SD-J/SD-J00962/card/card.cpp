#include<bits/stdc++.h>
//Trick||Treat!
#define int long long
const int N=1e6+10;
using namespace std;
int n,m,a[N],sum[N],t[N],f[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[i]=a[i];
	}
	int xia=1;
	int id=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(t[i]!=t[j]){
				f[i]=0;
			}else if(t[i]==t[j]){
				f[i]=1;
				for(int k=1;k<j;k++){
					t[k]=0;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			t[xia]=a[i];
			xia++;
		}
	}
	for(int i=1;i<=xia;i++){
		if(t[i]!=0) cout<<t[i]<<" ";
	}
	return 0;
}
