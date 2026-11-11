#include<bits/stdc++.h>
using namespace std;
#define int long long
long long c,T,n,d,f[2000005],a[2000005],sum; 
bool z(int x,int y){
	//cout<<x<<" "<<y<<"     ";
	if(a[y]-a[x]<=d)return 0;
	long long ans=0;
	f[x]=0;
	for(int i=x+1;i<=y;i++){
		f[i]=0x3f3f3f3f3f;
		for(int j=i-1;j>=x;j--){
			if(a[i]-a[j]>d)break;
			if(i==y){
				if(f[j]+1==f[i])ans++;
				else if(f[j]+1<f[i]){
					ans=1;
					f[i]=f[j]+1;
				}
			}
			else{
				f[i]=min(f[i],f[j]+1);
			}
			//cout<<j<<" "<<i<<" "<<f[j]<<" "<<f[i]<<endl;
		}
		if(f[i]==0x3f3f3f3f3f)return 0;
	}
	for(int i=x;i<=y;i++)cout<<f[i]<<" ";
	cout<<endl<<x<<" "<<y<<" "<<ans<<endl;
	return ans==2;
}
signed main(){
  	freopen("migrate.in","r",stdin);
   	freopen("migrate.out","w",stdout);
   	cin>>c>>T;
   	while(T--){
   		sum=0;
   		cin>>n>>d;
   		for(int i=1;i<=n;i++)cin>>a[i];
   		for(int i=1;i<n;i++){
   			for(int j=i+1;j<=n;j++){
   				if(z(i,j)){
   					//cout<<i<<" "<<j<<endl;
   					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
}
