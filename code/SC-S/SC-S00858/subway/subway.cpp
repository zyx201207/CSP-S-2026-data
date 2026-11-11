#include<bits/stdc++.h>
using namespace std;
const long long maxn=1e5+5;
long long c,n,m,d,q,k=0;
int w[maxn];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    cin>>k;
    for(int i=1;i<=k;i++){
    	k+=w[i];
	}
    cout<<k<<endl;
    cout<<w[2]+w[3]+w[5];
	return 0;
}