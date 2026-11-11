#include<bits/stdc++.h>
//#define int long long
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)

constexpr int N=2e6+10;
int ty,n,d,a[N];


int nxt[22][N],pre[22][N];

int findnxt(int u,int k){
	per(bit,std::__lg(n),0)
		if((k>>bit)&1)u=nxt[bit][u];
	return u;
}
int findpre(int u,int k){
	per(bit,std::__lg(n),0)
		if((k>>bit)&1)u=pre[bit][u];
	return u;
}
void solve1(){
	rep(i,0,n)nxt[0][i]=pre[0][i]=0;
	per(i,n,1){
		int l=i,r=n,pos=i;
		while(l<=r){
			int mid=l+r>>1;
			if(a[mid]-a[i]<=d)pos=mid,l=mid+1;
			else r=mid-1;
		}
		nxt[0][i]=pos;
	}
	rep(i,1,n){
		int l=1,r=i,pos=i;
		while(l<=r){
			int mid=l+r>>1;
			if(a[i]-a[mid]<=d)pos=mid,r=mid-1;
			else l=mid+1;
		}
		pre[0][i]=pos;
	}
//	rep(i,1,n)std::cout<<i<<" "<<pre[0][i]<<"d\n";
	rep(j,1,std::__lg(n))
		rep(i,1,n)
			nxt[j][i]=nxt[j-1][nxt[j-1][i]],
			pre[j][i]=pre[j-1][pre[j-1][i]];
	int ans=0;
	rep(i,3,n){
		int tm=pre[0][i]-1;
		int cnt=2,lst=tm;
//		if(nxt[0][pre[0][tm]]==tm)continue;
		while(tm>=1){
			bool fl=1;
			if(cnt==2){
				if(nxt[0][tm]!=pre[0][i]+1)fl=0;
			}
			else if(cnt==3){
				if(nxt[0][tm]!=lst+1)fl=0;
			}
			else{
				if(nxt[0][tm]!=lst)fl=0;
			}
			if(fl)++ans;
			else break;
			++cnt;lst=tm;
			tm=pre[0][tm];
		}
	}
	std::cout<<ans<<"\n";
}
void solve2(){
	std::cout<<"qwq";
}
void solve3(){
	int ans=0,l=1;
	rep(i,1,n){
		while(a[i]-a[l]>d)++l;
		ans+=i-l;
	}
	std::cout<<ans<<"\n";
}

void solve4(){
	std::cout<<"qwq";
}

void solve(){
	std::cin>>n>>d;
	rep(i,1,n)std::cin>>a[i];
	if(ty==13||ty==14){
		solve3();
		return ;
	}
	solve1();
//	if(ty<=10){
//		solve1();
//		return ;
//	}
//	else if(ty==11||ty==12){
//		solve2();
//		return ;
//	}
//	else if(15<=ty&&ty<=18){
//		solve4();
//		return ;
//	}
}

int main(){
	freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
	std::ios::sync_with_stdio(false),std::cin.tie(nullptr),std::cout.tie(nullptr);

	int _;std::cin>>ty>>_;
	while(_-->0){
		solve();
	}

	return 0;
}
