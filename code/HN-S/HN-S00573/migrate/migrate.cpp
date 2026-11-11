#include<bits/stdc++.h>
using namespace std;
#define int long long
int qwe,T;
int n,m;
int v[3000000];
void solve1(){
	if(n>3){
		int u=v[2]-v[1];
		m/=u;
		if(m==0||m*2>n||m<2){
			cout<<"0\n";
		}else{
			cout<<n-m*2+1<<"\n";
		}
		
	}else{
		cout<<0<<"\n";
	}
}
void solve3(){
	int u;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(v[i]-v[1]<=m&&v[n]-v[i]<=m){
			u=i;
			break;
		}
	} 
	int l,r;
	for(int i=1;i<=n;i++){
		l=i-1;
		r=n+1;
		while(l+1<r){
			int mid=(l+r)/2;
			if(v[mid]-v[i]<=m){
				l=mid;
			}else{
				r=mid;
			}
		}
		ans+=(n-l);
		if(u>=l){
			ans--;
		}
	}
	cout<<ans<<"\n";
	
}
void solve4(){
	int ans=0;
	map<int,int> mp;
	int w[50005];
	int cnt[50005];
	for(int sdf=1;sdf<=n;sdf++){
		for(int i=1;i<=n;i++){
			w[i]=1e9;
			cnt[i]=0;
		}
		w[sdf]=0;
		cnt[sdf]=1;
		for(int i=sdf;i<=n;i++){
			int l,r;
			l=i-1;
			r=n+1;
			while(l+1<r){
				int mid=(l+r)/2;
				if(v[mid]-v[i]<=m){
					l=mid;
				}else{
					r=mid;
				}
			}
			for(int j=i+1;j<=l;j++){
				if(w[j]==w[i]+1){
					cnt[j]+=cnt[i];
				}else if(w[j]>w[i]+1){
					w[j]=w[i]+1;
					cnt[j]=cnt[i];
				}
			}
		}
		mp.clear();
		for(int i=sdf;i<=n;i++){
			if(mp[cnt[i]-1]!=0){
				ans++;
			}
			if(cnt[i]!=0){
				mp[cnt[i]]++;
			}
			
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>qwe>>T;
	while(T--){
		cin>>n>>m;
		bool u=1;
		
		for(int i=1;i<=n;i++){
			cin>>v[i];
			if(i>=3&&v[i]-v[i-1]!=v[i-1]-v[i-2]){
				u=0;
			}
		}
		if(u==1){
			solve1();
		}else if(n<=50000){
			solve4();
		}else{
			solve3();
		}
		
	}
	return 0;
}

