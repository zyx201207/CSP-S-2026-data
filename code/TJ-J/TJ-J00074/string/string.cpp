#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
unsigned long long ans=0,n,sum=0,flag1;
struct stage{
	unsigned long long val,sum1;//val即为字母数量sum1为前缀和 
	char c1;//c为字母 
}a[200005];//每个阶段的字母数和字母 
int main(){
freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
//	printf("%lld",n);
a[0].sum1=0;
    for(int i=1;i<=n;i++){
    	scanf("%lld",&a[i].val);
    //	scanf("%c",&a[i].c1);
      cin>>a[i].c1;
    sum+=a[i].val;
    a[i].sum1=a[i-1].sum1+a[i].val;
	}
   /* if(sum%2==0){
    	flag1=sum/2+1;
    	int l=1,r=n;//l,r用来当下标 
    	while(a[k].sum1<flag1){
    		a[l].sum1-a[l].val;
		}
	}*/
	unsigned long long l=1,r=sum;
	string s="0";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i].val;j++){
			s+=a[i].c1;
		}
	}
	while(l<=r){
		if(s[l]!=s[r]){
			ans+=1;
			l+=1;
			r-=1;
			continue;
		}
		l+=1;
		r-=1;
	}
	cout<<ans;
	return 0;
}
