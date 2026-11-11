#include<bits/stdc++.h>
using namespace std;
struct node{
	long long num,ch;
}a[200005];
long long n,x,sum,sum2,ans;
char ch;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&x,&ch);
		a[i].num=x;
		a[i].ch=ch-'a';
		sum+=x;
	}
	sum2=sum;
//	printf("%lld",sum);
//	printf("%lld\n",n);
//	for(int i=1;i<=n;i++){
//		printf("%lld %lld\n",a[i].num,a[i].ch);
//	}
//	int nowi=1,nowj=n;
	for(int i=1,j=n;sum>0;){
//		printf("%d %d %lld\n",i,j,sum);
		long long minnum=min(a[i].num,a[j].num);
		long long minone;
		if(a[i].num<=a[j].num)minone=1;
		else minone=0;
		if(a[i].ch==a[j].ch){
//			puts("1");
			a[i].num-=minnum;
			a[j].num-=minnum;
			sum -=2*minnum;
			if(minone){
				i++;
			}else{
				j--;
			}
		}else{
//			puts("2");
			a[i].num-=minnum;
			a[j].num-=minnum;
			sum -=2*minnum;
			ans +=minnum;
			if(minone){
				i++;
			}else{
				j--;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
