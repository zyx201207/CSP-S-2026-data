//gaozixiu xianshidiliuzhongxue SN-J00697
#include<bits/stdc++.h>
using namespace std;
struct node{
	long long len;
	char x;
};
long long len;
node str[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		long long a;char b;
		scanf("%lld %c",&a,&b);
		str[i].len=a,str[i].x=b;
		len+=a;
		//~ cout<<1;
	}
	long long ans=0;
	int nowhave=str[1].len,nowhavee=str[n].len,nowid=1,nowidd=n;
	for(long long i=1,j=len;i<=j;i++,j--){
		if(nowhave==0)nowhave=str[++nowid].len;
		if(nowhavee==0)nowhavee=str[--nowidd].len;
		nowhave--,nowhavee--;
		if(str[nowid].x!=str[nowidd].x)ans++;
	}
	printf("%lld",ans);
	return 0;
}
