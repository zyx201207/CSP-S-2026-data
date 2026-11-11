#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 500005;

ll a[N];

int pcnt[N];
ll solcnt[N];
struct soll{
	ll cost;
	ll val;
	int cntnow;
};
vector<soll> sol[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n;
	ll m;
	cin >> n >> m;
	bool flag = true;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(i > 2){
			if(a[i] - a[i - 1] != a[2] - a[1]) flag=false;
		}
	}
	sort(a+1,a+n+1);
	if(flag){
		ll d = a[2] - a[1];
		ll t = 0;
		if(d==0){
			cout<<n;
			return 0;
		}
		while(++t){
			if(t*(t+1)*d/2>m || t>=n){
//				t--;
				break;
			} 
		}
		cout<<min(t,n);
		
		return 0;
	}
	map<int,ll> p;
	int diff=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]) {
			diff++;
			p[diff]=a[i];
			solcnt[diff]=1;
			soll tmp;
			tmp.cost=0;
			tmp.val=pcnt[diff-1];
//			tmp.cntnow=pcnt[diff-1];
			sol[diff-1].push_back(tmp);
//			cout<<sol[diff-1][0].cntnow<<endl;
//			memset(dp[diff]+1,dp[diff]+m+5,-1);
		}
		pcnt[diff]++;
//		solcnt[diff]++;
	}
//	cout<<diff<<endl;
	soll tmp;
	solcnt[diff]=1;
	tmp.cost=0;
	tmp.val=pcnt[diff];
//	tmp.cntnow=pcnt[diff];
	sol[diff].push_back(tmp);
//	cout<<tmp.val<<endl;
	ll ans =0;
	for(int i=1;i<=diff;i++){
//		cout<<"!I"<<i<<endl;
		for(int kp=0;kp<solcnt[i];kp++){
			ans=max(ans,sol[i][kp].val);
			for(int j=i+1;j<=diff;j++){
				
//				cout<<i<<" "<<kp<<" "<<j<<"CNTNOW"<<sol[i][kp].cntnow<<endl;
				if((p[j]-p[i])*sol[i][kp].val+sol[i][kp].cost<=m){
					solcnt[j]++;
					soll tmp;
					tmp.cost=(p[j]-p[i])*sol[i][kp].val+sol[i][kp].cost;
					tmp.val=sol[i][kp].val+pcnt[j];
					ans=max(ans,tmp.val);
//					tmp.cntnow=sol[i][kp].cntnow+pcnt[i];
//					cout<<tmp.cntnow<<" val "<<tmp.val<<endl;
					sol[j].push_back(tmp);
				}
				else{
				
					int rem=m-sol[i][kp].cost;
					int s=rem/(p[j]-p[i]) ;
//					cout<<j<<" "<<pcnt[j]<<endl;
					if(s+pcnt[j]>ans){
//						cout<<pcnt[j]<<endl;
//						cout<<s+pcnt[j]<<endl;
						solcnt[j]++;
						soll tmp;
						tmp.cost=(p[j]-p[i])*s+sol[i][kp].cost;
						tmp.val=pcnt[j]+s;
						ans=max(ans,tmp.val);
						sol[j].push_back(tmp);
					}
						
					
				}
			}
		}
	}
	cout<<ans<<endl;
} 
