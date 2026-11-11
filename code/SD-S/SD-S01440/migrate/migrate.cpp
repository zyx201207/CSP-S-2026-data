#include<bits/stdc++.h>
using namespace std;
const int N=2e6+100;
int C,T,n,d,a[N],dis[N];
vector<int> e[N];
priority_queue<pair<int,int>,vector< pair<int,int > >,greater<pair<int,int> > > h;
int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(a[i]-a[j])<=d){
					e[a[i]].emplace_back(a[j]);
					e[a[j]].emplace_back(a[i]);
				}
				else{
					break;
				}
			}
		}
	}
	return 0;
}

