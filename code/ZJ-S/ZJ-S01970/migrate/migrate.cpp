#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,s,sum1,sum2,ans,a[2000005],flag[2000005],p[2000005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		a[0]=-5e18;
		s=0,ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]-a[s]>d)
				flag[i]=++s;
			if(a[i]-a[i-1]>d)
				p[i]=1;
		}
		for(int i=1;i<=n;i++){
			sum1=sum2=0;
			for(int j=i+1;j<=n;j++){
				if(!flag[j])
					sum1++;
				else{
					if(sum1==2)sum2++;
					else break;
					if(p[j])break;
				}
			}
			ans+=sum2;
		}
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++){
			flag[i]=0;
			p[i]=0;
		}
	}
	return 0;
} 
