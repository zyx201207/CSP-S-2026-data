#include <bits/stdc++.h>
using namespace std;
const int MAXN =5*1e5+1;
int n,m,d=0;
int cnt = 1;
int a[MAXN];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++){
        cin >> a[i];
	}
    sort(a,a+n);
    for(int i=0;i<n;i++){
        d=a[i+1]-a[i];
        m-=d*(i+1);
        if(m < 0){break;}
        cnt+=1;
    }
    cout << cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
