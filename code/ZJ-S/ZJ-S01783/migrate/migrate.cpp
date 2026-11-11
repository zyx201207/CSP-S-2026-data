#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d,l[2000005];
long long cntn[2000005],ans;
long long ton[305][305];

void baoli(int st){
	for(int i=st;i<=n;++i)
		for(int j=st;j<=n;++j)
			ton[i][j]=0;
	for(int i=st;i<=n;++i)
		cntn[i]=0;
	cntn[st]=1;
	for(int x=st;x<n;++x){
		for(int i=x+1;i<=n;i++){
			if(l[i]-l[x]<=d){
				if(cntn[i]!=0&&cntn[i]==cntn[x]+1) ton[x][i]++;
				if(cntn[i]!=0) cntn[i]=min(cntn[i],cntn[x]+1);
				else cntn[i]=cntn[x]+1;
			}else continue;
		}
	}
	
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			if(ton[i][j]==1) ans++;
}

bool specialA(){
	long long cha=l[2]-l[1];
	for(int i=3;i<=n;++i)
		if(l[i]-l[i-1]!=cha) return false;
	return true;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;++i){
			scanf("%lld",&l[i]);
		}
		if(specialA()){
			printf("%lld\n",n-(d*2-1));
			
		}else if(n<=300){
			ans=0;
			for(int i=1;i<=n;++i)
				baoli(i);
			printf("%lld\n",ans);
		}
	}
	return 0;
}