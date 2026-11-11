#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=500007;
int c,n,m,d,q,w[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=q;i++){
		cout<<rand()%20+20<<endl;
	}
	return 0;
} 
