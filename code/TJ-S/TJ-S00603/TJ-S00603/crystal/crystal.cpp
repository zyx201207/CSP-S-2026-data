#include<bits/stdc++.h>
using namespace std;
long long a[500009],pre[500009];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	long long n,m,ans=0,f=1;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		pre[i] = pre[i-1]+a[i];
		if(i!=1&&a[i]!=a[i-1]){
			f=0;
		}
	}
	if(f==1){
		cout<<n<<endl;
		return 0;
	}
	for(int i = 1;i<=n;i++){
		for(int j = i+ans;j<=n;j++){
			long long mid;
			if(j-i+1<ans){continue;}
			mid=(pre[j]-pre[i-1])/(j-i+1);
			long long step=0,sum=0;
			for(int k = i;k<=j;k++){
				if(step+abs(a[k]-mid)<=m){
					step+=abs(a[k]-mid);
					sum++;
				}
			}
			ans=max(ans,sum);
		}
	}
	cout<<ans<<endl;
	return 0;
}
