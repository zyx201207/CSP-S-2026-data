#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=2e5+5;
int c,t;
int n;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	cin>>c>>t;
	while(t--){
		n=rand()%300+1;
		cout<<n<<'\n';
	}
	return 0;
}

