#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],k,a;
int t[505][500005],x,y,ans;
int main(){
	freopen("subway.in","r",stdin);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
	    for(int j=1;j<=k;j++){
	    	cin>>a>>t[i][j];
	    	
	    }
	}
	for(int i=0;i<q;i++){
		cin>>x>>y;
		ans=w[x]+w[y];
		for(int j=x;j<y;j++){
			ans+=t[j][1]+t[j][2];
				//cout<<t[j][o]<<endl;
				/*if(t[j][o]==0)break;
				if(o==y)break;*/
			
			
		}
		cout<<ans<<endl;
	}
	freopen("subway.out","w",stdout);
	return 0;
} /*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/