//crystal 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll n,m,a[5*N],maxn=INT_MIN,ans;
ll mi;
ll mb,dq,xy;
bool tsa,tsb;

void fb(){
	printf("%lld",m/(a[2]-a[1])+1);
}
long long cc=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	tsa=true;
	tsb=true;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			tsa=false;
		}
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
			tsb=false;
		}
	}
	if(tsb){
		fb();
		return 0;
	}
	sort(a+1,a+n+1);
	
	for(int i=1;i<=n;i++){
		ans=0;
		mb=a[i];
		mi=m;
		int j=1;
		while(mi&&i>j){
			dq=a[i-j];
			xy=mb-dq;
			if(mi>=xy){
				mi-=xy;
				ans++;
			}else{
				break;
			}
			j++;
		}
		maxn=max(ans+1,maxn);
	}
	
	printf("%lld",maxn);
	return 0;
} 
/*
5 5
1 2 4 6 8 10

5 5 
1 2 4 8 9
*/
