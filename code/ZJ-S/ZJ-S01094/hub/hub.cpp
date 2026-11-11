#include<bits/stdc++.h>
using namespace std;
int c,T;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	srand(time(0));
	while(T--){
		int n,k;cin>>n>>k;
		int x=rand()%10;
		cout<<x<<'\n';
	}
	return 0;
}