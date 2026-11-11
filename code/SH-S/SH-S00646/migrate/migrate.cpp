#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,d,lst[5005];
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		long long ans=0;
		long long len[305][305]={0};
		long long num[305][305]={0};
		for(int i=1;i<=n;i++)scanf("%lld",&lst[i]);
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(j==i)len[i][j]=0,num[i][j]=1;
				else if(lst[j]-lst[j-1]>d)break;
				for(int k=j+1;k<=n;k++){
					if(lst[k]-lst[j]<=d){
						if(len[i][j]+1==len[i][k])num[i][k]++;
						else if(len[i][j]+1<len[i][k]||len[i][k]==0)len[i][k]=len[i][j]+1,num[i][k]=num[i][j];
					}
					else break;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				if(num[i][j]==2)ans++;
			}
		}
		printf("%lld\n",ans);
	}
}
