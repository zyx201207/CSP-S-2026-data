#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
int main(){
using namespace std;
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    long long maxyu=0;
    for(int i=1;i<=n-m+1;i++){
	long long thisyu=a[i];
	for(int j=1;j<=m-1;j++){
            thisyu=thisyu&a[i+j];
	}
        maxyu=max(maxyu,thisyu);
    }
    cout << maxyu;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

