#include<bits/stdc++.h>
#define int long long
#define rep(l,r,i) for(int i=l;i<=r;i++)
#define rrep(l,r,i) for(int i=l;i>=r;i--)
#define rmp(v,mp) for(auto v:mp)
using namespace std;
void fre(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
}namespace ZXY{
	typedef long long ll;
	const int N=2e5+7;
	int a[N];char c[N];int n;
	struct node{
		int cnt;char c;
	}b[N],d[N];int tot1=0,tot2=0;
	void solve(){
		ios::sync_with_stdio(0);
		cin.tie(0);cout.tie(0);
		cin>>n;ll sum=0;
		rep(1,n,i)cin>>a[i]>>c[i];
		rep(1,n,i)sum+=a[i];
		ll L=sum/2,R=L,nowl=0,nowr=0;
		bool flg=0;
		rep(1,n,i){
			if(!flg){
				if(nowl+a[i]<=L)
					nowl+=a[i],b[++tot1]={a[i],c[i]};
				else{
					flg=1;
					b[++tot1]={L-nowl,c[i]};nowl=L;
					if(n%2==0)
						d[++tot2]={a[i]-b[tot1].cnt,c[i]},nowr+=a[i]-b[tot1].cnt;
					else if(a[i]-b[tot1].cnt-1>0)
						d[++tot2]={a[i]-b[tot1].cnt-1,c[i]},nowr+=a[i]-b[tot1].cnt-1;
				}
			}else nowr+=a[i],d[++tot2]={a[i],c[i]};
		}
		reverse(d+1,d+tot2+1);
		int len=b[1].cnt;char ch=b[1].c;
		int now=1;ll ans=0;
		rep(1,tot2,i){
			if(d[i].cnt<len){
				if(d[i].c!=ch)ans+=d[i].cnt;
				len-=d[i].cnt;
			}else{
				ll sum=len;now++;
				if(ch!=d[i].c)ans+=len;
				while(now<=tot1&&sum<=d[i].cnt){
					if(b[now].c!=d[i].c)ans+=b[now].cnt;
					sum+=b[now].cnt,now++;
				}now--;len=sum-d[i].cnt;ch=b[now].c;
				if(b[now].c!=d[i].c&&now<=tot1)ans-=sum-d[i].cnt;
			}
		}cout<<ans;
	}
}
signed main(){fre();ZXY::solve();}
//a2 //a2

