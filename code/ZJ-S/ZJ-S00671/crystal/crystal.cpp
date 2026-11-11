#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long rin(){
	long long ans = 0;
	int opt=  1;
	char t = getchar();
	while((t<'0'||t>'9')&&(t!='-'))t=getchar();
	if(t=='-'){
		opt=-1;t=getchar();
	}
	while(t>='0'&&t<='9'){
		ans = ans*10+t-'0';t=getchar();
	}
	return ans*opt;
}
void rout(long long d){
	if(d/10)rout(d/10);
	putchar('0'+d%10);
}
int n;long long m;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=rin();m=rin();
	for(int i = 1;i<=n;i++)a[i]=rin();
	sort(a+1,a+1+n);
	int l = 1;//[l,r]
	long long sum = 0;
	long long ans = 1;
	for(int r = 2;r<=n;r++){
		sum = sum+(r-l)*(a[r]-a[r-1]);
		while(sum>m&&l+1<=r){
			sum-=(a[r]-a[l++]);
		}
		ans = max(ans,r-l+1ll);
//		cout<<sum<<" "<<ans<<"\n";
	}
	rout(ans);
	return 0;
}
