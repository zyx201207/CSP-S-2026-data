#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=40;
long long a[N];
int ge(long long u){
	int o=0;
	while(u){
		u>>=1;
		o++;
	}
	return o;
}
bool st[N],ss[N];
int ma=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ma=max(ge(a[i]),ma);
	}
	long long ans=0;
	for(int i=ma-1;i>=0;i--){
		int cnt=0;
		memcpy(ss,st,sizeof st);
		for(int j=1;j<=n;j++){
			if(st[j])continue;
			if((a[j]>>i)&1){
				cnt++;
			}
			else ss[j]=1;
		}
		if(cnt>=m){
			ans+=1<<i;
			memcpy(st,ss,sizeof st);
		}
	}
	printf("%d",ans);
	return 0;
} 
