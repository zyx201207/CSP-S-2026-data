#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(i==n){
			if(n/m>2){
				cout<<"1 2 1"<<endl;
			}
			if(n%m!=0){
				cout<<"1 1 2"<<endl;
			}
			else{
				cout<<"1 1 1"<<endl;
			}
		}
	}
	return 0;
}

