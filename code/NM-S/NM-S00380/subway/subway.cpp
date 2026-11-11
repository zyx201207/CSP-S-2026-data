#include<bits/stdc++.h>
using namespace std;
int w[500005],k1[1005][1005],t[1005][1005];
int x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,i,k[100005],j,l,s=0,a,b;
	cin >> c >> n >> m >> d >> q;
	for(i=1;i<=m;i++){
	    cin >> w[i];
	}

	for(i=1;i<=n;i++){
        cin >> k[i];
        for(j=1;j<=k[i];j++){
            cin >> k1[i][j] >> t[i][j];
        }
	}
	for(i=1;i<=q;i++){
        cin >> x >> y;
        s=0;
        for(j=1;j<=n;j++){
            for(l=1;l<=k[i];l++){
                if(k1[j][l]==x ||k1[j][l]==y){
                    s+=t[j][l]+w[k1[j][l]];
                }
            }
        }
        cout << s << endl;
	}

    return 0;
}
