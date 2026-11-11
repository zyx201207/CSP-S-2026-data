#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,T,n,k;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		if(c==13||c==14){
			cout<<n/8-(k-1)/4+1<<"\n";
		}
		else{
			cout<<(n-k)/4<<"\n";
		}
	}
	return 0;
}
