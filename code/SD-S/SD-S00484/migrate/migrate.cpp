#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,n,cs[2000005];
ll d,x[2000005],r[2000005],ans;
void dfs(int w){
	for(int i=w;i<=n;i++){
		if(r[i]==0)break;
		if(r[i]==2)ans++;
		int l=i+1,ri=n,mid;
		while(l<=ri){
			mid=l+ri>>1;
			if(x[mid]-x[i]<=d)l=mid+1;
			else ri=mid-1;
		}
		for(int j=l-1;j>i;j--){
			if(cs[j]==0){
				cs[j]=cs[i]+1;
				r[j]+=r[i];
			}
			else{
				if(cs[i]+1==cs[j])r[j]+=r[i];
				else break;
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		ans=0;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		if(c<=10){
			for(int i=1;i<=n;i++){
				memset(r,0,sizeof(r));
				memset(cs,0,sizeof(cs));
				r[i]=1;
				dfs(i);
			}
			printf("%lld\n",ans);
		}
		else{
			ll len=x[2]-x[1];
			if(d<len||d/len==1)printf("0\n");
			else{
				ll mm=d/len;
				printf("%lld\n",max(0LL,(ll)(n)-(mm*2-1LL)));
			}
		}
	}
	return 0;
}

