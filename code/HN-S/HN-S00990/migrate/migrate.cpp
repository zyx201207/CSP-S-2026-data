#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=2e6+5;
int c,t,n,ans;
LL d,x[N];
bool bo[N];
void csh(){
	ans=0;
	for(int i=0;i<n+5;i++){
		bo[i]=0;
	}
}void wt(int o){
	if(o>=10)wt(o/10);
	char c;
	c=(o%10)+'0';
	putchar(c);
}int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		csh();
		scanf("%d%lld",&n,&d);
		for(int i=0;i<n;i++)scanf("%lld",&x[i]);
		if(n<4){
			putchar('0');
			putchar('\n');
			continue;
		}for(int i=0;i<n-3;i++)
			if(x[i+3]-x[i]>d)
				if(x[i+1]-x[i]<=d&&x[i+4]-x[i+2]<=d)bo[i]=1;
		int cnt=1;
		bool fx=0;
		for(int i=0;i<n-1;i++){
			if(bo[i]){
				if(fx)cnt=1,fx=0;
				else fx=1;
				i+=3;
				continue; 
			}if(x[i+1]-x[i]<=d)cnt++;
			else{
				if(fx)ans+=cnt;
				cnt=1,fx=0;
			}
		}ans+=cnt;
		wt(ans),putchar('\n'); 
	}return 0;
}//rp++ 
