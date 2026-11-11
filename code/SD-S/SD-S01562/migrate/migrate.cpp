#include<bits/stdc++.h>
using namespace std;

namespace smilemask{
	#define rd read()
	#define int long long
	typedef long long ll;
	typedef pair<int,int> PII;
	inline ll read(){
		ll num=0,sign=1;char ch=getchar();
		while(!isdigit(ch)){
			if(ch=='-') sign=-1;
			ch=getchar();
		}while(isdigit(ch)){
			num=(num<<1)+(num<<3)+ch-'0';
			ch=getchar();
		}return num*sign;
	}
	
	const int N=5e3+10;
	
	int n;
	ll x[N],d,ans;
	PII f[N];
	
	PII operator +(const PII &a,const PII &b){
		if(a.first==b.first) return {a.first,a.second+b.second};
		if(a.first<b.first) return a;
		return b;
	}
	
	void solve(){
		for(int i=1;i<=n;i++){
			f[i]={0,1};
//			cout<<i<<endl;
			for(int j=i+1;j<=n;j++){
				f[j]={n+1,0};
				for(int k=i;k<j;k++)
					if(x[j]-x[k]<=d)
						f[j]=f[j]+f[k];
				f[j].first++;
//				cout<<j<<' '<<f[j].first<<' '<<f[j].second<<endl;
				if(f[j].second==2) ans++;
			}
		}
	}

	void Main(){
		n=rd,d=rd,ans=0;
		for(int i=1;i<=n;i++)
			x[i]=rd;
		solve();
		reverse(x+1,x+n+1);
		solve();
		cout<<ans<<endl;
	}
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--) smilemask::Main();
	return 0;
}

