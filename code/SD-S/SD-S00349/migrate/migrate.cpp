#include<bits/stdc++.h>
#define lllld long long
#define endl '\n'
using namespace std;
long long x[2000003];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		bool speciB=0;
		for(int i=2;i<=n-1;i++){
			if(x[i]-x[1]<=d&&x[n]-x[i]<=d){
				speciB=1;
				break;
			}
		}
//		if(speciB){
//			cout<<0<<endl;
//			continue;
//		}
		if(x[n]-x[1]<=d){
			cout<<0<<endl;
			continue;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				if(x[j]-x[i]<=d)continue;
				if(x[j]-x[i]==d*2-1){
					cnt++;
//					cout<<i<<" "<<j<<endl;
					continue;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
/*
//freopen feropen froopen fropen freeopen luogu 1488910
*/
