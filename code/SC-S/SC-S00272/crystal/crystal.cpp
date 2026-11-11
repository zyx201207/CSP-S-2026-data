#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],n,m,max_num,num;
int q[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(1+a,1+a+n);
	int num=0;
	int head=1,tail=0;
	for(int i=1;i<=n;i++){
		if(ans<=m){
			ans+=num*(a[i]-a[i-1]);
			num++;q[++tail]=a[i];
		}
		while(ans>m){
			ans-=a[i]-q[head];
			head++;num--;
		}
		max_num=max(max_num,num);
	}
	printf("%lld",max_num);
	return 0;
} 