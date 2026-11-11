#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e5;

int n,m;
int ans=-4e18;
int a[N];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int ma=-4e18,mi=4e18;
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		mi=min(mi,a[i]);
	}
	
	sort(a+1,a+1+n);
	
	stack<int> st;
	int cnt=1;
	
	for(int i=mi;i<=ma;i++){
		for(;cnt<=n&&a[cnt]<=i;cnt++) st.push(a[cnt]);
		stack<int> st2;
		int nm=m;
		int an=0;
		while(nm>0&&!st.empty()){
			an++;
			nm-=(i-st.top());
			st2.push(st.top());
			st.pop();
		}
		if(nm<0) an-=1;
		ans=max(ans,an);
		while(!st2.empty()) st.push(st2.top()),st2.pop();
	}
	
	cout<<ans;
	
	return 0;
}
