#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200010],ans;
bool w[200010];
signed main(){
	ans=(1<<31)-1;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];w[i]=1;
	}
	for(int k=30;k>=0;k--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(w[i]&&(a[i]&(1<<k))){
				cnt++;
			}
		}
		if(cnt>=m){
			for(int i=1;i<=n;i++){
				if(!(a[i]&(1<<k))){
					w[i]=0;
				}
			}
		}
	}
	for(int i=1,j=0;i<=n;i++){
		if(w[i]==1)ans&=a[i],j++;
		if(j==m)break;
	}
	cout<<ans;
	return 0;
}

