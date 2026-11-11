#include<bits/stdc++.h>
using namespace std;

#define int long long
using P = pair<int,int>;

const int N=2e5+5;

int sz,n;
int a[N];
char c[N];
int l[N],r[N];
vector<pair<P,char>>fro,bac;
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	
	if(n==1){
		cout<<0<<endl;
		return;
	}
	
	sz=0;
	for(int i=1;i<=n;i++){
		l[i]=sz+1;
		r[i]=l[i]+a[i]-1;
		sz+=a[i];
	}
	
	int L=sz/2;
	int R=sz/2+1+(sz%2);
	
	for(int i=1;i<=n;i++){
		if(l[i]>L){
			break;
		}
		fro.push_back({{l[i],min(r[i],L)},c[i]});
	}
	
	for(int i=n;i>=1;i--){
		if(r[i]<R){
			break;
		}
		bac.push_back({{sz-r[i]+1,sz-max(R,l[i])+1},c[i]});
	}
	
	
	int ans=0;
	
	int ll,r_1,r_2;
	char c_1,c_2;
	
	int id_1=0;
	int id_2=0;
	
	ll=1;
	
	r_1=fro[id_1].first.second;
	r_2=bac[id_2].first.second;
	
	c_1=fro[id_1].second;
	c_2=bac[id_2].second;
	while(id_1<(int)fro.size()&&id_2<(int)bac.size()&&ll<=sz/2){
		
		r_1=fro[id_1].first.second;
		r_2=bac[id_2].first.second;
		
		c_1=fro[id_1].second;
		c_2=bac[id_2].second;
		
		if(r_1==r_2){
			ans+=(c_1!=c_2)*(r_2-ll+1);
			ll=r_1+1;
			id_1++;
			id_2++;
		}else if(r_1<r_2){
			ans+=(c_1!=c_2)*(r_1-ll+1);
			ll=r_1+1;
			id_1++;
		}else if(r_1>r_2){
			ans+=(c_1!=c_2)*(r_2-ll+1);
			ll=r_2+1;
			id_2++;
		}
		
	}
	cout<<ans<<endl;
}

int t_;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	
	t_=1;
//	cin>>t_;
	while(t_--){
		solve();
	}
	
//	cout.flush();
	
	return 0;
}
