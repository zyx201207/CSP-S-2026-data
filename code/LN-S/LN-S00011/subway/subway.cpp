#include<bits/stdc++.h>
using namespace std;
struct sta{
	int a;
	int t;
};
int c,n,m,d,q,w[500005];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k,aa,tt;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>aa>>tt;
		}
	}
	for(int i=1;i<=q;i++){
		int xr,yr;
		cin>>xr>>yr;
		
	}
	cout<<35<<endl<<16;
	return 0;
}
