#include<bits/stdc++.h>
using namespace std;
int n;
long long sum,ans;
const int N=2e5+1;
struct cl{
	long long l,r,num;
	char c;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		long long b;
		scanf("%lld %c",&b,&a[i].c);
		a[i].l=sum+1;
		a[i].r=sum+b;
		a[i].num=b;
		sum+=b;
	}
	int l=1,r=n;
	while(l<r){
		long long l1=a[l].l,r1=a[l].r,l2=sum-a[r].r+1,r2=sum-a[r].l+1;
		if(r1<r2){
			if(a[l].c!=a[r].c){
				ans+=r1-l2+1;
				if(l1>l2) ans-=l1-l2;
			}
			l++;
		}else if(r1>r2){
			if(a[l].c!=a[r].c){
				ans+=r2-l1+1;
				if(l2>l1) ans-=l2-l1;
			}
			r--;
		}else{
			if(a[l].c!=a[r].c) ans+=min(a[l].num,a[r].num);
			l++;r--;
		}
	}
	printf("%d",ans);
	return 0;
}
