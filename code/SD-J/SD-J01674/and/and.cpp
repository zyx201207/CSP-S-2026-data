#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],tmp[N],si,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	si=n;
	for(int p=30;p>=0;p--){
		int d=1<<p,cnt=0;
		for(int i=1;i<=si;i++){
			if(a[i]&d){
				tmp[++cnt]=a[i];
			}
		}
		if(cnt>=m){
			ans+=d,si=cnt;
			for(int i=1;i<=si;i++){
				a[i]=tmp[i];
			}
		}
	}
	printf("%d",ans);
	return 0;
} 
/*
5 3
31 3 1 15 7

*/
