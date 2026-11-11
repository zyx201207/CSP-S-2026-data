#include<bits/stdc++.h>
using namespace std;
struct bett{
	int a;
	int b;
};
bool cmp(bett a,bett b){
	return a.a>=b.a;
}
bett b[555555];
long long n,m,a[555555],ans=-1e9,sy,need,now,an;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		b[i].a=(b[i-1].a+(a[i]-a[i-1]))/2;
		b[i].b=i;
	}sort(b+1,b+n+1,cmp);
	for(long long j=1;j<=n;j++){
		int i=b[j].b;
		sy=m;
		now=i-1;
		an=1;
		while(sy>0){
			need=a[i]-a[now];
			if(sy>=need&&now>0){
				sy-=need;
				now--;
				an++;
			}else break;
		}ans=max(ans,an);
	}cout<<ans;
	return 0;
} 
