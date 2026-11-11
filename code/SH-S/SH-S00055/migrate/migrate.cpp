#include<bits/stdc++.h>
#define I using
#define hate namespace
#define CSPS std
I hate CSPS;
typedef long long ll;
ll x[2000010];
void solve1(ll n,ll d){//<=300的时候可以暴力
	//此时我们直接记录两个的可达性 
	bool keda[350][350];
	ll mlj[350][350],ljs[350][350];
	ll fkeda[350];
	//记录1步到位情况 
	for(int i=1;i<=n; i++) {
		fkeda[i]=i;
		for(int j=i+1;j<=n;j++){
			keda[i][j]=keda[j][i]=(x[j]-x[i]<=d);
			if(!keda[i][j]){//此处不可达 
				ljs[i][j]=ljs[j][i]=0;
				for(int k=j;k<=n;k++)mlj[i][k]=mlj[k][i]=114514191981054188LL;//后面暂时不可达 
				break;
			}
			fkeda[i]=j;//最远能到 
			mlj[i][j]=1,mlj[j][i]=1,ljs[i][j]=1,ljs[j][i]=1;
		}
	}
	fkeda[n]=n;
	//先跑最短路 
	for(int i=n;i>=1;i--){
		for(int j=n;j>=1;j--){
			if(i==j){
				mlj[i][j]=0;continue;//其实没用 
			}
			for(int k=n;k>=1;k--){
				mlj[i][j]=min(mlj[i][j],mlj[i][k]+mlj[k][j]);//扫一遍 
			}
		}
	}
	for(int i=n;i>=1;i--){//倒序分析，这样前面分析的时候后面已经分析过了 
		for(int j=n;j>=1;j--){
			if(mlj[i][j]==1)continue;//不用看了不可能了
			ljs[i][j]=0;
			for(int k=n;k>=1;k--){
				ll tmp=mlj[i][j];if(tmp==114514191981054188LL)continue;//最小路径长度 
				if(mlj[i][k]+mlj[k][j]==tmp){//那么可以叠加路线数了
					ljs[i][j]+=ljs[i][k]*ljs[k][j];
				}
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=fkeda[i]+1;j<=n;j++){//省掉那些一步到位的事情，那些肯定长度只是1，不可能是2条路 
			if(ljs[i][j]==2){
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}
void solve(){
	ll n,d;
	cin>>n>>d;ll tmp; 
	fill(x,x+n+10,0);
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	solve1(n,d);
}
int main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
