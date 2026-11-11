#include<bits\stdc++.h>
using namespace std;
long long ans=0;
struct node{
	int len,who;
}a[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%s",&a[i].len,&a[i].who);
	int l=1,r=n;
	while(l<r){
		if(a[l].who!=a[r].who)ans+=min(a[l].len,a[r].len);
		if(a[l].len>a[r].len){
			a[l].len-=a[r].len;
			r--;
		}
		else if(a[l].len==a[r].len){
			l++;
			r--;
		}
		else{
			a[r].len-=a[l].len;
			l++;
		}
		
	}
	printf("%lld",ans);
	return 0;
}
