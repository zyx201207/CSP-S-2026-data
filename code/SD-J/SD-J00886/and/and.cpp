#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
#define ll long long
int n,m,a[N],cnt[31],ans;
bool f[31][N];
int c(int pos){
	int res=0;
	for(int i=1;i<=n;i++){
		if(f[pos][i]==1&&((a[i]&ans)>=ans)) res++;
	}
	return res;
} 
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i+1);
		int x=a[i];
		while(x){
			cnt[int(log2(x))]++;
			f[int(log2(x))][i]=1;
			x=x-pow(2,int(log2(x)));
		}
	}
	for(int i=30;i>=0;i--){
		if(cnt[i]<m) continue;
		if(c(i)>=m) ans+=pow(2,i);
	}
	printf("%d",ans);
	return 0;	
}
/*
in:
3 2
5 5 6
out:
5
*/
