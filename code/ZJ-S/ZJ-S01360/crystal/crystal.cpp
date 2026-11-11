#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int maxn=5e5+5;
void read(LL& x){
	char c; bool f=0;
	while((c=getchar())<48) f|=(c==45);
	x=c-48;
	while((c=getchar())>47) x=(x<<3)+(x<<1)+c-48;
	x=(f ? -x : x);
}
void read(int& x){
	char c; bool f=0;
	while((c=getchar())<48) f|=(c==45);
	x=c-48;
	while((c=getchar())>47) x=(x<<3)+(x<<1)+c-48;
	x=(f ? -x : x);
}
LL a[maxn]; LL m; int n;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);
	LL sum=0; int ans=1; int l=1;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		while(l<i&&1ll*(i-l+1)*a[i]-sum>m) sum-=a[l++];
		if(1ll*(i-l+1)*a[i]-sum<=m) ans=max(ans,i-l+1);
	}
	printf("%d\n",ans);
	return 0;
}