#include<iostream>
#include<algorithm>
#include<cmath>
#define int long long
using namespace std;
int n,m;
int a[200005];
int to2(int x){
	int ret=0;
	while(x){
		if(x&1){
			ret++;
		}
		x>>=1;
	}
	return ret;
}
int to20(int x){
	int ret=0;
	while(x){
		if((x&1)==0){
			ret++;
		}
		x>>=1;
	}
	return ret;
}
bool cmp(int x,int y){
	int t2x=to2(x),t2y=to2(y);
	if(t2x==t2y){
		return to20(x)<to20(y);
	}
	else return t2x>t2y;
}
int ans=0;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n,cmp);
	ans=a[1];
	for(int i=2;i<=m;i++){
		ans=ans&a[i];
	}
	printf("%d",ans);
	return 0;
}
