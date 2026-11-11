#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;
int n,cnt=1,max_;
long long m,a[N],num,m_;
void dfs(int step){
	if(step-max_<0) return ;
	cnt=1;
	m_=m;
	for(int i=step-1;i>0;i--){
		if(m_>=a[step]-a[i]) {
			m_-=(a[step]-a[i]);
		    cnt++;
		}	
	}
	max_=max(max_,cnt);
	dfs(step-1);
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	m_=m;
	for(int i=n-1;i>0;i--){
		if(m_<a[n]-a[i]) break;
		m_-=(a[n]-a[i]);
		cnt++;
	}
	max_=cnt;
	dfs(n-1);
	cout<<max_;
	return 0;
}


