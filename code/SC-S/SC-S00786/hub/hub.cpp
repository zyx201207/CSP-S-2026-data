#include<bits/stdc++.h>
using namespace std;

const int mn=2e6+2;
int c,n,t;
long long d,x[mn];
long long ans;

long long check(int j,int i){
	if(j==i)return 0;
	long long cnt=1;
	for(int k=j+1;k<=i&&x[k]-x[j]<=d;k++)cnt+=check(k,i);
	return cnt;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	scanf("%d",&c);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		scanf("%d",&d);
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&x[i]);
			for(int j=i-2;j>0;j--){
				if(check(j,i)==2)ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}