#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[114514*9/2],ans=0,F[114514*9/2];
int f(int x){
	if(F[x]) return F[x];
	int cnt=0,sum=0;
	for(int i=x;i>0;i--){
		if(sum+a[x]-a[i]<=m){
			cnt++;
			sum+=a[x]-a[i];
		}else break;
	}
	F[x]=cnt;
	return cnt;
}
void SA(){
	int p=rand()%n+1;
	double temp=1145.14,dtemp=0.99178;
	while(temp>=0.0000001919810){
		int d=(n-p)*exp(-rand()/temp);
		int fp=f(p),fdp=f(d+p);
		ans=max(ans,max(fp,fdp));
		if(fdp>fp||rand()*1.0/rand()<exp((fp-fdp)*1.0/temp)) p=d+p;
		temp*=dtemp;
		d=(1-p)*exp(-rand()/temp);
		fp=f(p),fdp=f(d+p);
		ans=max(ans,max(fp,fdp));
		if(fdp>fp||rand()*1.0/rand()<exp((fp-fdp)*1.0/temp)) p=d+p;
		temp*=dtemp;
		if(clock()/CLOCKS_PER_SEC>0.95) return;
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	srand(time(0)^rand()+325+rand()*77);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++){
//		if(i+100<=n&&f(i+100)>f(i)&&f(i+100)<f(i+101)) i+=100;
//		ans=max(ans,f(i));
//	}
	while(clock()/CLOCKS_PER_SEC<0.95) SA();
	cout<<ans;
}
//I'll AFO
