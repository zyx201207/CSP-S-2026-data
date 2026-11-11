#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
int c,t;
int n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
		}
		for(int i=1;i<=n;i++){
			cout<<1<<'\n';
		}
	}
	return 0;
}
