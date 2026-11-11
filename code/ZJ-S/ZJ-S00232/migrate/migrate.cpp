#include<bits/stdc++.h>
using namespace std;
long long SS,T,n,d,i,j,k,t,flag,ans,dis[2000010],sum[2000010],a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>SS>>T;
	while(T--){
		cin>>n>>d;
		ans=0;
		for(i=1;i<=n;i++)
			cin>>a[i];
		for(i=1;i<=n;i++){
			for(j=0;j<=n;j++)dis[j]=0,sum[j]=0;
			sum[i]=1;
			for(j=i+1;j<=n;j++){
				flag=1;
				t=lower_bound(a+i,a+j+1,a[j]-d)-(a+1);
				t++;
				dis[j]=dis[t]+1;
				for(k=t;k<=j;k++){
					if(dis[k]==dis[t])sum[j]+=sum[k];
					if(sum[j]>2){
						flag=0;break;
					}
				}
				if(flag&&sum[j]==2)
					ans++;
			}
		}
		cout<<ans<<"\n";
		for(i=0;i<=n;i++)sum[i]=0,dis[i]=0;
	}
	return 0;
}
//0 2
//5 3
//-2 -1 0 1 2
//6 2
//-4 -3 -2 -1 3 6 

//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5