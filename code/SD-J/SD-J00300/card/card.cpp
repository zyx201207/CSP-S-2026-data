#include<bits/stdc++.h>
#define rep(l,r,i) for(int i=l;i<=r;i++)
#define rrep(l,r,i) for(int i=l;i>=r;i--)
#define rmp(v,mp) for(auto v:mp)
using namespace std;
void fre(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
}namespace ZXY{
	const int N=2e5+7;
	int n,a[N],m,now[N],tot=0,cnt[N],sum[N];
	namespace solve2{
		typedef long long ll;
		const int N=2e5+7,M=2e5+7;
		int pre[N],cnt[M];
		void solve(){
			ll sum=0;
			rep(1,n,i)pre[a[i]]++;
			rep(1,m,i){
				sum+=pre[i],cout<<sum;
				if(i!=n)cout<<' ';
			}
		}
	}
	void solve(){
		ios::sync_with_stdio(0);
		cin.tie(0);cout.tie(0);
		cin>>n>>m;
		bool flg=1;
		rep(1,n,i)cin>>a[i];
		rep(1,n,i)if(a[i]<a[i-1])flg=0;
		if(flg&&n<=5000)return solve2::solve();
		rep(1,n,i){
			tot=0;
			fill(sum+1,sum+m+1,0);
			sum[a[i]]=1;now[++tot]=a[i];
			rep(i+1,n,j){
				if(sum[a[j]]){
					int pos=0;
					rep(1,tot,k)
						if(now[k]==a[j]){pos=k;break;}
					while(tot>=pos)sum[now[tot]]--,--tot;
					sum[a[j]]++;now[++tot]=a[j];
				}else sum[a[j]]++,now[++tot]=a[j];
			}rep(1,tot,j)cnt[now[j]]++;
		} rep(1,m,i)cout<<cnt[i]<<' ';
	}
}
int main(){fre();ZXY::solve();}


