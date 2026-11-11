#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,a[10050],b[10050],cnt=0,ans=0;
int main(){
    freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >>c>>t;
	for(int i=1;i<=t;i++){
		cin >>n>>m;
		cnt=0;
		ans=0;
		memset(b,0,sizeof(b));
		for(int j=1;j<=n;j++){
			cin >>a[i];
		}
		b[1]=0;
		for(int j=2;j<=n;j++){
			if(a[j]-a[j-1]<=m){
				b[j]=0;
			}else{
				b[j]=1;
			}
		}
		for(int j=2;j<=n;j++){
			cout <<b[j]<<" ";
			if(b[j]==0){
				ans++;
			}else{
				if(ans>=3){
					cnt+=(ans-2);
				}
				ans=0;
			}
		}
		cnt+=(ans-2);
		cout <<cnt;
	}
    return 0;	
}
