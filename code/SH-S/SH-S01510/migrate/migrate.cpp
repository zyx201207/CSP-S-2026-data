#include<bits/stdc++.h>
using namespace std;
int a[2000010],b[2000010],cnt[2000010],rd[2000010],rdd[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,ans=0;
	cin>>c>>t;
	for(int i=1;i<=20;i++){
		rd[i]=INT_MAX-5;
	}
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		for(int j=2;j<=n;j++){
			b[j]=abs(a[j]-a[j-1]);
		}
		cnt[1]=1;
		rd[1]=0;
		rdd[1]=0;
		for(int j=2;j<=n;j++){
			for(int k=1;k<j;k++){
				if((b[j]+b[k])*(j-k)/2<=d){
					rd[4]=INT_MAX;
					rd[j]=min(rd[j],rd[k]+1);
					cout<<rd[4]<<endl;
				}
			}
			for(int k=1;k<=j;k++){
				if((a[j]+a[k])*(j-k)/2<=d){
					rdd[j]=rdd[k]+1;
					if(rdd[j]==rd[j]){
						cnt[j]+=cnt[k];
					}
				}
			}
			if(cnt[j]%2==0){
				ans++;
			}
		}
		cout<<ans;
		ans=0;
		for(int i=1;i<=2000010;i++){
			cnt[i]=0;
			rdd[i]=0;
			rd[i]=INT_MAX;
		}
		
	}
	return 0;
}
