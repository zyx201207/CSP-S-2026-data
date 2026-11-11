#include<ctime>
#include<iostream>
#include<random>
using namespace std;
int c,n,m,d,q;

inline void solve(){
	srand(time(0));
	int c,t;
	cin>>c>>t;
	while(t--){
		cout<<rand()%100<<"\n";
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;	
}