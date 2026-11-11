#include<bits/stdc++.h>
using namespace std;
struct num_str{
	long long num;
	char s;
};
num_str a[200000];
long long n,x=0,ans = 0,y= 0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		scanf("%lld%s",&a[i].num,&a[i].s);
		x+=a[i].num;
	}
	long long l = 1,r = n;
	while(y<x){
		long long min1 = min(a[l].num,a[r].num);
		a[l].num -= min1;
		a[r].num -= min1;
		y+=2*min1;	
		if(a[l].s!=a[r].s)ans+=min1;
		if(a[l].num==0)l++;
		if(a[r].num==0)r--;
	}
	printf("%lld",ans);
	return 0;
}