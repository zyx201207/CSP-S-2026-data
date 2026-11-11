#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m;
ll a[500005];
ll need[500005];

inline void read(){
	cin >> n >> m;
	for(int i=1;i<=n;++i) cin >> a[i];
	sort(a+1,a+1+n);
	return;
}

bool check(int id){
	return (need[id] <= m);
}

inline void work_need(int st){
	need[st]=0;
	for(int i=st+1;i<=n;++i){
		need[i] = need[i-1] + (i-st)*(a[i]-a[i-1]); 
	}
}

int ans;
inline void work_ans(int st){
	int l=st,r=n;
	while(l <= r){
		int mid = (l+r)/2;
		if(check(mid)){
			ans=max(ans,mid-st+1);
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return;
}

inline void write(){
	cout << ans;
	return;
}

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	read();
	for(int i=1;i<n;++i){
		work_need(i);
	    work_ans(i);
	}
	
	write();
	
	return 0;
}