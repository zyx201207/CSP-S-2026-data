#include<bits/stdc++.h>
using namespace std;
const int N=2e4,M=510;
int c,n,m,d,q,w[N],l[N],ll[N][N],t[N];
map<int,int>p[N];long long ans;
int k,kk;
int a[100][100];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
	    int s;cin>>s;
        int a1,a2,b1,b2;
	    cin>>a1>>b1>>a2>>b2;
	    l[a1]=a2;l[a2]=a1;
	    ll[a1][a2]=b1+b2;ll[a2][a1]=b1+b2;
	}
	for(int i=1;i<=q;i++){
	    int b,c;cin>>b>>c;
	    ans=w[b]+w[c];
	    while(b!=c){
		    ans+=ll[b][l[b]];
		    b=l[b];
		}
		ans+=ll[b][c];
		cout<<ans<<endl;
	}
	return 0;
}
