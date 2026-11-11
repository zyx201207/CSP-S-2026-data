#include<bits/stdc++.h>
using namespace std;
const int I=200010;
struct node{
	int a;
	char c;
	long long s;
}x[I];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n;
	long long ans=1,cnt=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&x[i].a,&x[i].c);
		x[i].s=ans;
		ans+=x[i].a;
	}
	ans-=1;
	long long midd=ans/2+ans%2;
	int l=1,r=n;
	long long aa=1,bb=ans;
	char ac=x[1].c,bc=x[n].c;
	while(aa<=midd&&bb>=midd){
		long long mi;
		ac=x[l].c,bc=x[r].c;
		if(ac!=bc){
			cnt+=max(aa,ans-bb+1)-min(aa,ans-bb+1);
		}
		if(aa<ans-bb+1){
			aa+=x[l].a;
			mi=x[l].a;
			l++;
		}
		if(aa>ans-bb+1){
			bb-=x[r].a;
			mi=x[r].a;
			r--;
		}
		if(aa==ans-bb+1){
			if(x[l+1].a<x[r-1].a){
				l++;
				aa+=x[l].a;
			}
			else{
				r--;
				bb-=x[r].a;
			}
		}
	}
	printf("%lld",cnt);
	return 0;
}/*
6
2 a
2 b
1 c
1 a
1 d
2 a
*/
