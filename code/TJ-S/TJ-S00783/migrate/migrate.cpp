#include<bits/stdc++.h>
using namespace std;
int T,c,n,a[5002][5002],num,tot,b[5002],cnt;
unsigned long long d;
long long x[5002];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		num=0;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		memset(a,0x3f,sizeof(a));
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(x[j]-x[i]<=d){
					a[i][j]=1;
					b[i]=j;
				}
				else
					break;
		for(int i=1;i<=n;i++)
			for(int j=b[i];j<=n;j++)
			{
				if(a[i][j]==1)	continue;
				cnt=0;
				for(int k=i+1;k<=j;k++){
					if(a[i][k]+a[k][j]==a[i][j])
						cnt++;
					if(a[i][k]+a[k][j]<a[i][j]){
						cnt=1;
						a[i][j]=a[i][k]+a[k][j];
					}
					if(cnt>3)
						break;
				}
				if(cnt==2)
					num++;	
			}
		cout<<num<<endl;
	}
	return 0;
}
