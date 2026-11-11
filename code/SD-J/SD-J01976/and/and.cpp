#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,x,er_j[N][35],k,maxx=1,ans[35],l,sum,las;
bool flag[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		k=0,er_j[i][1]=x&1;
		while(x!=0){
			k++;
			er_j[i][k]=x&1;
			x>>=1;
		}
		maxx=max(maxx,k);
	}
	k=0,las=maxx+1;
	for(int i=1;i<=n;i++) for(int j=1;j<=maxx;j++) if(er_j[i][j]!=1) er_j[i][j]=0;
	for(int i=maxx;i>=1;i--){
		int cnt=0;
		for(int j=1;j<=n;j++) if(!flag[j]) cnt+=er_j[j][i];
		if(cnt>=m){
			ans[i]=1;
			for(int j=1;j<=n;j++) if((!flag[j])&&(er_j[j][i]==0)) flag[j]=1;
			las=i;
		}
		else ans[i]=0;
		if(cnt==m){
			k=i;
			break;
		}
	}
	if(k==0){
		if(las>1) ans[las-1]=0;
		for(int i=1;i<=maxx;i++) sum+=(ans[i]*(1<<l)),l++;
		printf("%d",sum);
	}
	else{
		for(int i=k;i>=1;i--) ans[i]=1;
		for(int i=k;i>=1;i--) for(int j=1;j<=n;j++) if(!flag[j]) ans[i]=ans[i]&er_j[j][i];
		for(int i=1;i<=maxx;i++) sum+=(ans[i]*(1<<l)),l++;
		printf("%d",sum);
	}
	return 0;
}
