#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	srand(time(0));
	while(t--){
		cout<<rand()%10;
	}
	return 0;
} 