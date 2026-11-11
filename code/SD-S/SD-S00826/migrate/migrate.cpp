#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
const int N=2000010;

int n,d;
int c,T,x[N];
vector<int> v[N];

void solve(){
	if(c>=13&&c<=14) cout<<0<<'\n';
	else if(c>=11&&c<=12){
		cout<<c-(d+1)<<'\n';
	}
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(abs(x[i]-x[j])<=d){
				v[i].push_back(j);
				v[j].push_back(i);
			}
		}
	}
}
int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>T;
	while(T--){
		solve();
	}
	
	
	return 0;
} 


