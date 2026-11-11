#include<bits/stdc++.h>
using namespace std;
long long c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int rp=1;rp<=t;rp++){
		long long n,d,x[200005],cnt=0,l=0,r=0,ans=0;
		cin>>n>>d;
		x[0]=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(x[i]-x[i-1]<=d){
				if(cnt==0){
					l=i;
				}
				cnt++;
			}
			if(x[i]-x[i-1]>d && cnt!=0){
				r=i-1;
				long long zsx=x[l]+d;
				for(int j=l;j<=r;j++){
					if(x[j]<zsx) cnt--;
					//else{
					//	zsx=x[j]+d;
					//}
				}
				if(cnt>3){
					ans++;
				}
			}
			
		}
		cout<<ans<<endl;
	}
	return 0;
}