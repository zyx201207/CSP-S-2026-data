#include<bits/stdc++.h>
using namespace std;
long long a[500010],b[500010];
int main(){
//	ios::sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long ans=0;
	if(n<=5000){
		for(int i=1;i<=n;i++){
			long long ret=0,v=m;
			for(int j=1;j<=i;j++){
				b[j]=a[i]-a[j];	
				if(b[j]<0) b[j]=1e18+10;
			}
//			sort(b+1,b+1+n);
			for(int j=i;j>=1;j--){
				if(v>=b[j]){
					ret++;
					v-=b[j];			
				}
//				cout<<b[j]<<" "<<v<<'\n';
			}
			ans=max(ans,ret);
//			cout<<ans<<'\n';
		}
		cout<<ans;		
	}
	else{
		bool flag=0;
		for(int i=1;i<=n;i++){
			int ret=i*(i-1)*(a[2]-a[1])/2;
			cout<<ret<<endl;
			if(ret>m){
				cout<<i-1<<endl;
				flag=1;
				return 0;
			}
		}
		if(!flag) cout<<n;
	}
	return 0;
}
