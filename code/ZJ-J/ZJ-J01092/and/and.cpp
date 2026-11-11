#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL N=2e5+5;
LL n,m,maxn=-1e12;
LL fact[35];
LL a[N],d[N],xb[N];
bool vis[N];
LL disk[N][35];
LL qpow(LL a,LL b){
	LL res=1;
	while(b){
		if(b&1){
			res=res*a;
		}
		a=a*a;
		b>>=1;
	}
	return res;
}
void dfs(LL x,LL cnt){
	if(cnt>m){
		return ;
	}
	if(x==n+1){
		if(cnt==m){
			LL s=d[1];
			for(LL i=2;i<=cnt;i++){
				s=s&d[i];
			}
			maxn=max(maxn,s);
		}
		return ;
	}
	dfs(x+1,cnt);
	d[cnt+1]=a[x];
	dfs(x+1,cnt+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(LL i=1;i<=32;i++){
		fact[i]=qpow(2,i)-1;
	}
	cin>>n>>m;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	bool f0123=0;
	LL d0=0,d1=0,d2=0,d3=0;
	for(LL i=1;i<=n;i++){
		if(a[i]>3){
			f0123=1;
			break;
		}else{
			if(a[i]==0){
				d0++;
			}else if(a[i]==1){
				d1++;
			}else if(a[i]==2){
				d2++;
			}else{
				d3++;
			}
		}
	}
	if(!f0123){
		if(d3>=m){
			cout<<"3\n";
		}else if(d3+d2>=m){
			cout<<"2\n";
		}else if(d3+d1>=m){
			cout<<"1\n";
		}else{
			cout<<"0\n";
		}
		return 0;
	}
	if(m==n){
		LL sum=a[1];
		for(LL i=1;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum<<"\n";
		return 0;
	}
	if(m==1){
		cout<<a[n]<<"\n";
		return 0;
	}
	if(m==2&&n<=2000){
		LL mx=-1;
		for(LL i=1;i<=n;i++){
			for(LL j=1;j<=n;j++){
				if(i!=j){
					mx=max(mx,a[i]&a[j]);
				}
			}
		}
		cout<<mx<<"\n";
		return 0;
	}
	bool f=0;
	for(LL i=1;i<=n;i++){
		bool fl=0;
		for(LL j=1;j<=30;j++){
			if(a[i]==fact[j]){
				fl=1;
				break;
			}
		}
		if(!fl){
			f=1;
			break;
		}
	}
	if(!f){
		cout<<a[n-m+1]<<"\n";
		return 0;
	}else if(n<=20){
		dfs(1,0);
		cout<<maxn<<"\n";
		return 0;
	}else{
		for(LL i=1;i<=n;i++){
			LL sx=a[i],g=0;
			while(sx){
				disk[i][++g]=sx%2;
				sx/=2;
			}
		}
		LL sum=0;
		for(LL i=30;i>=1;i--){
			LL cnt=0;
			LL t=0;
			for(LL j=1;j<=n;j++){
				if(disk[j][i]&&!vis[j]){
					cnt++;
				}else{
					xb[++t]=j;
				}
			}
			if(cnt>=m){
				for(LL j=1;j<=t;j++){
					vis[xb[j]]=1;
				}
				sum+=qpow(2,i-1);
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
