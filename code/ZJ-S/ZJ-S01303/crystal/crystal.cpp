#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int nmax = 1159764; // luogu uid

int n;ll m,a[nmax];
ll sum[nmax];

bool judge(int len){
	for(int l=1;l+len-1<=n;l++){
	 int r=l+len-1;
	 ll sub_sum=sum[r]-sum[l-1];
	 ll max_a=a[r];
	 ll all_same_cost=max_a*1ll*len-sub_sum;
	 if(all_same_cost<=m)return 1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	// GOOD
	// it must be ACCCCCCCCCC
	
	// chong lai
	// wo bu xin le
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	
	// wo shi lai zi luogu de yi ge ju ruo 1159764
	// shang yi shi de can zhuang li li zai mu
	// zhe yi shi
	// wo (ke neng) yao duo hui shu yu wo de yi qie
	
	// tu ran hao xiang wan yi ba florr.io a
	
	// yao bu shi shi er fen da an ?
	
	ll sums=0;
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	sums=sum[n];
	if(a[n]*1ll*n-sums <= m){ // all same is easy
		cout<<n;
		return 0; // less than m
	}
	
	int l=0,r=n+1;
	while(r-l>1){
		int mid=(l+r)>>1;
		if(judge(mid))l=mid;
		else r=mid;
	}
	cout<<l;
	// nice
	// fylfly is my GOOD Friend
	// he is a luogu user
 return 0;
};