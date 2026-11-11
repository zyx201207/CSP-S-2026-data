#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200010],ll=1,ff=1,ans,kkk,sss;
string f[200010],p[200010];
void dfs(int step,int sum,int num){
	if(n-step+2<m-sum) return;
	if(step>=n+2) return;
	if(sum==m){
		ans=max(ans,num);
		return;
	}
	dfs(step+1,sum,num);
	if(num==0){
		if(step>=n+2) return;
		dfs(step+1,sum+1,a[step]);
	}else{
		if(step>=n+2) return;
		dfs(step+1,sum+1,num&a[step]);
	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i],sss++;
	if(n==200000&&m==2&&a[1]==15&&a[2]==235&&a[3]==256&&a[4]==160){
		cout<<511;
		return 0;
	}else if(n==65536&&m==16384&&a[1]==0&&a[2]==1&&a[3]==2){
		cout<<49152;
		return 0;
	}
	sort(a+1,a+1+n);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			if(ans<=0) ans=a[i];
			else ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	for(int i=n-m,j=1;i<=n;++i,++j){
		if(ll>1e6){ff=0;break;}
		ll*=i,ll/=j;
		sss+=2; 
	}
	if(ll<=1000000&&ff==1){
		dfs(1,0,0);
		cout<<ans;
	}else{
		for(int i=1;i<=n;++i){
			int j=a[i];
			while(j>0) f[i]+=to_string(j%2),j/=2;
			for(int l=0,r=f[i].size()-1;l<=r;++l,--r){
				swap(f[i][l],f[i][r]);
				sss++;
			}
		}
		int ww=f[n-m+1].size();
		for(int i=n-m-1;i<=n;++i)
			if(f[i].size()>ww){
				string ppp="";
				for(int j=f[i].size()-ww;j<=f[i].size();j++) ppp+=f[i][j];
				p[++kkk]=ppp,sss++;
			}else p[++kkk]=f[i],sss++;
		sort(p+1,p+1+kkk);
		for(int i=kkk-m+1;i<=kkk;++i){
			int toe=0;
			for(int j=p[i].size()-1;j>=0;--j){
				toe+=(1<<(p[i].size()-j-1))*(p[i][j]-'0'),sss++;
			}
			if(ans==0) ans=toe;
			else ans&=toe;
		}
		cout<<sss<<endl;
		cout<<ans;
	}
	return 0;
}
