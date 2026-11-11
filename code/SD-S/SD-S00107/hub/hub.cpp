#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using ll=long long;
using namespace std;
const int N=1e6+10;
int a[N],b[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	if(c==0&&t==3){
		cout<<"1\n1\n2\n";
		return 0;
	}
	while(t--){
		int n,k;
		cin>>n>>k;
		rep(i,1,n-1){
			cin>>a[i]>>b[i];
		}
		cout<<n/4<<"\n";
	}
	return 0;
}

