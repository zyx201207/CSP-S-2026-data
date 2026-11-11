#include<bits/stdc++.h>
using namespace std;
struct node{
	long long qz,z;
}a[200005];
long long tp[35]={1},n,m,st[35],t[200005][35],cnt,back,ans;
bool cmp(node a,node b){
	return a.qz>b.qz;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=1;i<=30;i++){
		tp[i]=tp[i-1]*2;
	}
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i].z);
		cnt=a[i].z;
		back=0;
		while(cnt>0){
			t[i][back++]=cnt%2;
			cnt/=2;
		}
		/*
		for(int j=0,k=back-1;j<k;j++,k--){
			swap(t[i][j],t[i][k]);
		}
		*/
		for(int j=0;j<back;j++){
			if(t[i][j]==1){
				st[j]++;
			}
//			printf("%lld ",t[i][j]);
		}
//		printf("\n");
	}
	for(int j=30;j>=0;j--){
//		printf("%lld ",st[j]);
		if(st[j]>=m){
			for(int i=1;i<=n;i++){
				if(t[i][j]==1){
					a[i].qz+=tp[j];
				}
			}
		}
	}
	sort(a+1,a+n+1,cmp);
	/*
	for(int i=1;i<=n;i++){
		printf("%lld ",a[i].z);
	}
	*/
	ans=a[1].z;
	for(int i=2;i<=m;i++){
		ans=(ans & a[i].z);
	}
	printf("%lld",ans);
	return 0;
}
