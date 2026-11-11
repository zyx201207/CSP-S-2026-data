#include<cstdio>
#include<algorithm>
const int MAXN=2e5+5;
struct str{
	int x;
	char c;
}a[MAXN];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i].x,&a[i].c);
	}
	int l=1,r=n;
	long long ans=0;
	while(l<r){
		if(a[l].c!=a[r].c){
			int t=std::min(a[l].x,a[r].x);
			ans+=t;
			a[l].x-=t,a[r].x-=t;
			if(a[l].x==0) l++;
			if(a[r].x==0) r--;
		}else{
			int t=std::min(a[l].x,a[r].x);
			a[l].x-=t,a[r].x-=t;
			if(a[l].x==0) l++;
			if(a[r].x==0) r--;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
