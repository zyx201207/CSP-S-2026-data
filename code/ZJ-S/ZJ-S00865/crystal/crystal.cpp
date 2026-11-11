#include<bits/stdc++.h>
#define int long long
#define il inline
#define put putchar
using namespace std;
typedef pair<int,int> pii;
il int rd(){
	int sum=0,p=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')p=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		sum=sum*10+(ch-'0');
		ch=getchar(); 
	}
	return sum*p;
}
il void wr(int x){
	if(x<0)put('-'),x=-x;
	if(x>9)wr(x/10);
	put(x%10+'0');
}
const int JYAAKIOI=1e18,N=5e5+5;
int n,a[N],sum,m,ans,b[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=rd();m=rd();
	for(int i=1;i<=n;++i)a[i]=rd();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)b[i]=b[i-1]+a[i];
	for(int i=1;i<=n;++i){
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[i]*mid-(b[i]-b[i-mid])<=m)ans=max(ans,mid),l=mid+1;
			else r=mid-1;
		}
	}
	wr(ans);
	return 0;
}