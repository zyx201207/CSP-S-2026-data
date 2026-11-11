#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=10000011;
int c,T,n,d;
int f[N],g[N],x[N],x_[N],f_[N],pre[N],suf[N];
void sv(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		f[i]=g[i]=f_[i]=suf[i]=0;
		x_[n-i+1]=-x[i];
	}
	for(int i=1,now=1;i<=n;i++){
		while(now<n&&x[now+1]-x[i]<=d) now++;
		suf[i]=now;
		if(now!=i){
			f[now]++;
			if(x[now]-x[i-1]>d) f[now]+=f[i];
		}
	}
	for(int i=1,now=1;i<=n;i++){
		while(now<n&&x_[now+1]-x_[i]<=d) now++;
		pre[n-i+1]=n-now+1;
		if(now!=i){
			f_[now]++;
			if(x_[now]-x_[i-1]>d) f_[now]+=f_[i];
		}
	}
	for(int i=1;i<=n/2;i++) swap(f_[i],f_[n-i+1]);
	
	int ans=0;
	
	for(int i=2;i<=n-1;i++){
		int X=pre[i+1],Y=suf[i];
		ans+=(pre[i+2]-X)*(Y-suf[i-1]);
		if(pre[i+2]==X||suf[i-1]==Y) continue;
		ans+=f[X]*f_[Y];
	}
	/*
	for(int i=1;i<=n;i++){
		int A=suf[i],B=suf[i]-1,C=suf[i]-2;
		int S=suf[A];
		if(suf[B]!=A&&suf[B]==S&&suf[C]!=S){
			cout<<i<<" "<<S<<endl;
			ans+=(f[i]+1)*(f_[S]+1);
		}
		else if(suf[B]!=A&&suf[B]<S&&suf[C]<suf[B]){
			cout<<i<<"-"<<suf[B]<<endl;
			ans+=f[i]+1;
		}
	}
	*/
	/*
	for(int i=1;i<=n;i++){
		for(int j=i+3;j<=n;j++){
			if(suf[suf[i]]==suf[suf[i-1]) ans+=(f[i]+1)*(f_[j]+1); 
		}
	}*/
	//cout<<ans;
	/* 
	int ans=0;
	for(int i=2,lst=1;i<=n;i++){
		while(x[i]-x[lst]>d) lst++;
		if(lst==i) continue;
		g[i]=g[lst];
		if(lst<i-1) g[i]+=f[lst+1];
		ans+=g[i];
		cout<<i<<" "<<f[i]<<" "<<g[i]<<endl;
	}
	*/
	cout<<ans<<endl;
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>T;
	while(T--) sv();
	return 0;
}
//Oct31==Dec25? 
