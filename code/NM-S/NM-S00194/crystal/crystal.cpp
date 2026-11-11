#include<bits/stdc++.h>
#define int long long
#define go(x)(cout<<x<<'\n',void())
#define go1(x)(cout<<x<<' ',void())
#define go2(x)(cout<<x,void())
#define in(x)(cin>>x,void())
#define in1(x,y)(cin>>x>>y,void())
#define in2(x,y,z)(cin>>x>>y>>z,void())
#define vi vector<int>
#define vc vector<char>
#define ve vector 
using namespace std;
void solve(){
	int n,m,k,ans=-9;
	in1(n,m);
	priority_queue<int,vi,greater<int> > a;
	int c[n+1]={0}; 
	for(int i=0;i<n;i++){
		cin>>k;
		a.push(k);
	}
	if(m==0){
		go(1);
		return ;
	}
	for(int i=1;i<n;i++){
		c[i]=a.top();
		a.pop();
		int ka=m,sum=0;
		for(int j=i;j>=0;j--){
			int p=c[i]-c[j];
			if(ka-p>=0){
				sum++;
				ka=ka-p;
			}
			else{
				ans=max(ans,sum);
				break;
			}
		} 
		ans=max(ans,sum);
	}	
	go(ans);
	return ;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1;
	while(t--) solve();
	return 0;
}
