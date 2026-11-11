#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ldb=long double;
using db=double;
using i128=__int128;
using uint=unsigned int;
using ull=unsigned long long;
int T;
int c;
const int N=2e6+10;
ll a[N];
void T_solve(){
	int n;
	ll d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int r=i;r<=n;r++){
			vector<int> pos;
			pos.push_back(i);
			int j=i;
			while(1){
				while(j<=r&&a[j]-a[pos.back()]<=d){
					j++;
				}
				j--;
				if(j==pos.back()){
					break;
				}
				pos.push_back(j);
			}
			if(pos.back()!=r){
				pos.clear();
				continue;
			}
			if(pos.size()>2){
				ll cnt=0;
				for(int op=0;op<pos.size()-2;op++){
					for(int k=pos[op]+1;k<pos[op+1];k++){
						if(a[k]-a[pos[op]]<=d&&a[pos[op+2]]-a[k]<=d){
							cnt++;
						}
					}
				}
				if(cnt==1){
					ans++;
				}
			}
			pos.clear();
		}
	}
	cout<<ans<<'\n';
}
void T_solve1112(){
	int n;
	ll d;
	cin>>n;
	cin>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int op=0;
	for(int j=2;j<=n;j++){
		if(a[j]-a[1]<=d){
			op++;
		}
		else{
			break;
		}
	}
	if(op==0||op==1){
		cout<<0<<'\n';
		return ;
	}
	op*=2;
	cout<<max(0,n-op+1)<<'\n';
}
void T_solve1314(){
	int n;
	ll d;
	cin>>n;
	cin>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<0<<'\n'; 
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>T;
	while(T--){
		if(c<=10){
			T_solve();
		}
		else if(c>=11&&c<=12){
			T_solve1112();
		}
		else{
			T_solve1314();
		}
	}
	return 0;
}

