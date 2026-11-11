#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q =0;
const int MAXm =5*1e5+5;
const int MAXn =505;
const int MAXq =1e5+1;
int w[MAXm],a[MAXn][10010],t[MAXn][1010],x[MAXq],y[MAXq],sum[MAXq],k[1010];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++){
        cin >> w[i];
	}
	for(int i=1;i<=n;i++){
        cin >> k[i];
        for(int j=1;j<=k[i];j++){
            cin >> a[i][j] >> t[i][j];
        }
	}
	for(int r=1;r<=q;r++){
        cin >> x[r] >> y[r];
	}
	for(int r=1;r<=q;r++){
	    for(int i=1;i<=n;i++){
            sort(a[i],a[i]+k[i]);
            if(binary_search(a[i],a[i]+k[i],x[r])==true&&binary_search(a[i],a[i]+k[i],y[r])==true)sum[r] = w[x[r]] + t[x[r]][x[r]] + t[x[r]][y[r]] +w[y[r]];
	    }
	}
	for(int r=1;r<=q;r++){
        cout << sum[r] << endl;
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}

