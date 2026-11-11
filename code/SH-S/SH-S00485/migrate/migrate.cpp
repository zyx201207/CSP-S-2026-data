#include<bits/stdc++.h>
#define int long long
using ll=long long;
const int maxn=2e6+6;
int c,t;
int N,n;
ll d;
ll x[maxn],a[maxn];
int r[maxn],l[maxn];
int numl[maxn],numr[maxn],lenl[maxn],lenr[maxn];
ll work(){
	/*
	std::cout<<n<<"\n";
	for(int i=1;i<=n;i++){
		std::cout<<x[i]<<" ";
	}
	std::cout<<"\n";*/
	r[n]=n;int p=n;
	for(int i=n-1;i>=1;i--){
		while(x[p]-x[i]>d) p--;
		r[i]=p;
	//	std::cout<<r[i]<<" ";
	}
	//std::cout<<"\n";
	p=1;l[1]=1;
	for(int i=2;i<=n;i++){
		while(x[i]-x[p]>d) p++;
		l[i]=p;
	//	std::cout<<l[i]<<" ";
	}
	//std::cout<<"\n";
	for(int i=1;i<=n;i++){
		lenl[i]=l[i]==l[i-1]?lenl[i-1]+1:1;
	}
	r[n+1]=1e9;
	for(int i=n;i>=1;i--){
		lenr[i]=r[i]==r[i+1]?lenr[i+1]+1:1;
	}
	numr[n]=0;
	for(int i=n-1;i>=1;i--){
		int nxt=r[i];
		if(l[nxt]!=i) numr[i]=0;
		else numr[i]=lenl[nxt]+numr[nxt];
	}
	numl[1]=0;
	for(int i=2;i<=n;i++){
		int nxt=l[i];
		if(r[nxt]!=i) numl[i]=0;
		else numl[i]=lenr[nxt]+numl[nxt];
	}
	ll ans=0;
	for(int u=1;u<n;u++){
		int v=r[u];
		if(v==n)break;
		if(v==u+1) continue;
		int w=r[v];
		if(l[w]==v){
			int ww=w-lenl[w];
			if(ww!=v and l[ww]==v-1){
				ans+=lenl[ww];
				if(l[v-1]==u){
					ans+=(numl[u])*lenl[ww];
				}
			}
		}
		else if(l[w]==v-1){
			ans+=lenl[w];
			if(l[v-1]==u){
				ans+=(ll)(numl[u])*(numr[w]);
				ans+=(ll)(lenl[w])*numl[u];
				//std::cout<<"?"<<u<<" "<<v<<" "<<w<<" "<<(ll)(numl[u]+1)*(numr[w])+(ll)(lenl[w])*numl[u]<<"\n";
			}
			else{
				
			}
		}
	}
	for(int u=n;u>1;u--){
		int v=l[u];
		if(v==1)break;
		if(v==u-1) continue;
		int w=l[v];
		if(r[w]==v){
			int ww=w+lenr[w];
			if(ww!=v and r[ww]==v+1){
				if(r[v+1]==u){
					ans+=(numr[u])*lenr[ww];
				}
			}
		}
		else if(r[w]==v+1){
			if(r[v+1]==u){
				//ans+=(ll)(numl[u])*(numr[w]);
				ans+=(ll)(lenr[w])*numr[u];
				//std::cout<<"?"<<u<<" "<<v<<" "<<w<<" "<<(ll)(numl[u]+1)*(numr[w])+(ll)(lenl[w])*numl[u]<<"\n";
			}
			else{
				
			}
		}
	}
	return ans;
}
void solve(){
	std::cin>>N>>d;
	for(int i=1;i<=N;i++){
		std::cin>>a[i];
	}
	int lst=1;
	ll ans=0;
	for(int i=1;i<=N;i++){
		if(i>1 and a[i]-a[i-1]>d){
			for(int j=lst;j<i;j++){
				x[j-lst+1]=a[j];
			}
			n=i-lst;
			ans+=work();
			lst=i;
		}
	}
	for(int j=lst;j<=N;j++){
		x[j-lst+1]=a[j];
	}
	n=N-lst+1; ans+=work();
	std::cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	std::cin>>c>>t; while(t--) solve();
	//std::cerr<<std::clock()*1000.0/CLOCKS_PER_SEC<<"ms\n";
}
/*
0 1
10 285714285714285708
-1000000000000000000 -714285714285714292 -428571428571428584 -238095238095238112 -142857142857142876 -47619047619047640 142857142857142832 428571428571428540 714285714285714248 999999999999999956

0 1
10 333333333333333327
-1000000000000000000 -666666666666666673 -333333333333333346 -111111111111111128 111111111111111090 222222222222222199 333333333333333308 444444444444444417 666666666666666635 999999999999999962
*/
