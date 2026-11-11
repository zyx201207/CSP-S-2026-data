#include<bits/stdc++.h>
using namespace std;
int a[500010];
long long b[500010];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	if(n<=5000){
		b[1]=a[1];
		for(int i=2;i<=n;i++){
			b[i]=b[i-1]+a[i];
		}
		for(int i=2;i<=n;i++){
			for(int j=i;j>0;j--){
				if((i-j+1)*a[i]-b[i]+b[j-1]<=m){
					ans=max(ans,i-j+1);
				}
			}
		}
	}else{
		int cha=a[2]-a[1];
		for(int i=3;i<=n;i++){
			if(a[i]-a[i-1]!=cha){
				cha=0;
				break;
			}
		}
		if(cha){
			int i=1;
			while(i*(i+1)/2*cha<=m){
				i++;
			}
			ans=i;
		}
	}
	cout<<ans;
	return 0;
}

