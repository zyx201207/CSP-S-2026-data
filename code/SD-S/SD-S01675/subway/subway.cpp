#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=q;i++){
		cout<<i%n<<"\n";
	}
	return 0;
}
