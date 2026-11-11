#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5000+91;
int x[N],n,d; 

struct fq{
	int minn;
	int num;
}tr[N<<4];

void change(int p,int l,int r,int x,int v){
	if(l==r){
		tr[p].minn=min(tr[p].minn,v);
		tr[p].num=1;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid) change(p*2,l,mid,x,v);
	else change(p*2+1,mid+1,r,x,v);
	tr[p].minn=min(tr[p*2].minn,tr[p*2+1].minn);
	if(tr[p*2].minn > tr[p*2+1].minn) tr[p].num=tr[p*2+1].num;
	if(tr[p*2].minn < tr[p*2+1].minn) tr[p].num=tr[p*2].num;
	if(tr[p*2].minn == tr[p*2+1].minn) tr[p].num=tr[p*2].num+tr[p*2+1].num;
}

fq ask(int p,int l,int r,int L,int R){
	if(L>R){
		fq res;
		res.minn=2e18,res.num=0;
		return res;
	}
	if(L<=l && r<=R){
		return tr[p];
	}
		
	int mid=l+r>>1;
	fq fql,fqr,res;
	fql.minn=fqr.minn=res.minn=2e18,fql.num=fqr.num=res.num=0;
	if(L<=mid) fql=ask(p*2,l,mid,L,R);
	if(R>mid) fqr=ask(p*2+1,mid+1,r,L,R);
	res.minn=min(fql.minn,fqr.minn);
	if(fql.minn<fqr.minn) res.num=fql.num;
	if(fql.minn>fqr.minn) res.num=fqr.num;
	if(fql.minn==fqr.minn) res.num=fql.num+fqr.num;
	return res;
}

void init(){
	for(int j=0;j<(N<<4);j++){
		tr[j].minn=2e18;
		tr[j].num=0;
	}
}

void solve(){
	memset(x,0,sizeof x);
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	sort(x+1,x+n+1);
	int ans=0;
	for(int i=1;i<=n;i++){//start;
		for(int j=0;j<(N<<4);j++){
			tr[j].minn=2e18;
			tr[j].num=0;
		}
		change(1,1,N,i,0);
		for(int j=i+1;j<=n;j++){//end
			int pos=upper_bound(x+i,x+n+1,x[j]-d)-x-1;
			fq res=ask(1,1,N,pos,j-1);
			int f=res.minn+1;
			//cout<<max(pos,i)<<" ";
			if(res.minn>=2e18) break;
			if(res.num==2) {
				ans++;
				//cout<<i<<" "<<j<<" "<<f<<" "<<res.num<<endl;
			}
			change(1,1,N,j,f); 
		}
	//	cout<<endl;
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--) solve();
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/