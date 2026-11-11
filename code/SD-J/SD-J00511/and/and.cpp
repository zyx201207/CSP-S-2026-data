#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
struct node{
	long long num;
	int id;
}a[N];
long long s[N],pow_two[35],ans=0;
bool cmp(node x,node y){
	return x.num>y.num;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	pow_two[0]=1;
	for(int i=1;i<=31;i++)
		pow_two[i]=pow_two[i-1]*2;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i].num);
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	if(n<=2000){
		for(int L=1;L<=n-m+1;L++){
			long long now=a[L].num;
			for(int j=1;j<m;j++){
				now&=a[L+j].num;
			}
			ans=max(ans,now);
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(i>1) s[i]=s[i-1]&a[i].num;
			else s[i]=a[i].num;
		}
		for(int i=m;i<=n;i++){
			long long now=s[i]&s[i-m+1];
			ans=max(ans,now);
		}
	}
	printf("%lld",ans);
	return 0;
}
/*
#1
4 2
3 15 12 12
#2
5 3
31 3 1 15 7
#3


*/
