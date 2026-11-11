#include<bits/stdc++.h>

using namespace std;



ifstream fin("migrate.in");

ofstream fout("migrate.out");

#define cin fin

#define cout fout



using i64=long long;



const int N=5e3+5;



int n;

i64 d,x[N];

int lr[N],rl[N],rp[N],lp[N];



int num(int l,int r){

	if(x[r]-x[l]<=d||x[r]-x[l]>2*d) return -1;

	return upper_bound(x+l+1,x+r,x[l]+d)-lower_bound(x+l+1,x+r,x[r]-d);

}



i64 opt[N][N];



void clear(){

	for(int i=1;i<=n;++i) fill(opt[i],opt[i]+n+2,0);

}



void add(int x,int y,int a,int b,int d){

	if(x>y||a>b) return;

	// cerr<<x<<" "<<y<<" "<<a<<" "<<b<<" "<<d<<"\n";

	opt[x][a]+=d;

	opt[y+1][a]-=d;

	opt[x][b+1]-=d;

	opt[y+1][b+1]+=d;

}



struct Pair{

	int l,r;

};



i64 E[305][305],cnt[305][305];



inline i64 norm(i64 a){

	return min(a,3ll);

}



void work(){

	cin>>n>>d;

	for(int i=1,p=1;i<=n;++i){

		cin>>x[i];

		while(x[i]-x[p]>d) ++p;

		lp[i]=p;

	}

	for(int i=n,p=n;i>=1;--i){

		while(x[p]-x[i]>d) --p;

		rp[i]=p;

	}

	if(n<=300){

		for(int i=1;i<=n;++i) fill(E[i]+1,E[i]+n+1,1e18),fill(cnt[i]+1,cnt[i]+n+1,0);

		for(int i=1;i<=n;++i) for(int j=1;j<=n;++j){

			if(i==j) E[i][j]=0,cnt[i][j]=1;

			else if(abs(x[i]-x[j])<=d) E[i][j]=1,cnt[i][j]=1;	

		}

		for(int k=1;k<=n;++k)

			for(int i=1;i<=n;++i) 

				for(int j=1;j<=n;++j) if(i!=k&&k!=j){

					i64 val=E[i][k]+E[k][j],tim=norm(cnt[i][k]*cnt[k][j]);

					if(E[i][j]>val) E[i][j]=val,cnt[i][j]=tim;

					else if(E[i][j]==val) cnt[i][j]=norm(cnt[i][j]+tim);

				}

		int ans=0;

		for(int i=1;i<=n;++i) for(int j=i+1;j<=n;++j) if(cnt[i][j]==2) ++ans;

		cout<<ans<<"\n";

		return;

	}

	for(int i=1;i<=n;++i){

		rl[i]=upper_bound(x+i,x+rp[i]+1,x[i-1]+d)-x;

		lr[i]=lower_bound(x+lp[i],x+i+1,x[i+1]-d)-x-1;

	}

	for(int l=1;l<=n;++l){

		for(int r=l+1;r<=n;++r){

			int k=num(l,r);

			if(k<=1) continue;

			int t=1;

			if(k>2) t=2;

			vector<Pair> L={{l,l}},R={{r,r}};

			for(int i=l;;){

				if(lp[i]<=lr[i]) L.push_back({lp[i],lr[i]});

				else break;

				if(i==lp[i]) break;

				i=lp[i];

			}

			for(int i=r;;){

				if(rl[i]<=rp[i]) R.push_back({rl[i],rp[i]});

				else break;

				if(i==rp[i]) break;

				i=rp[i];

			}

			for(auto[a,b]:L) for(auto[c,d]:R) add(a,b,c,d,t);

		}

	}

	i64 ans=0,big=0;

	for(int i=1;i<=n;++i)

		for(int j=1;j<=n;++j){

			opt[i][j]+=opt[i-1][j]+opt[i][j-1]-opt[i-1][j-1];

			if(opt[i][j]==1) ++ans;

			

		}

	cout<<ans<<"\n";

}



signed main(){

	int sid,T;

	for(cin>>sid>>T;T--;work(),clear());

	return 0;

}



struct Code{

	Code(){ ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); }

	~Code(){ fout.flush(),fin.close(),fout.close(); }

} wtl;



