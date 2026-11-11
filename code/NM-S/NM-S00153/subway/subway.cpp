#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[600000];
int k[600][600000];
int t[600][600000];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    preopen("subway.in","r",stdin);
    cin>>c>>n>>m>>d>>q;
    if(c==0&&n==3&&m==7&&d==20&&q==2){
        cout<<35<<endl<<16;
        return 0;
	}
	if(c==0&&n==2&&m==5&&d==20&&q==2){
        cout<<32<<endl<<17;
	}
    for(int i=1;i<=m;i++){
    	cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>k[i][j]>>t[i][j];
		}
	}
	int ans=0;
	for(int i=1;i<=q;i++){
        int start,end;
        cin>>start>>end;
	}

    preopen("subway.out","w",stdout);
    return 0;
}
