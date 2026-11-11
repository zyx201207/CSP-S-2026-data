#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5;
const int M = 1e8+5;
int n,m,a[N],b[N],ans,diff[N],f[M];

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i],diff[i]=a[i]-a[i-1];
    bool isDeng=true;
    for(int i=1;i<=n;i++)
        if(diff[i]!=diff[i-1]){
            isDeng=false;
            break;
    }
    if(isDeng){
        cout<<m/diff[1];
    }else{
        sort(a+1,a+1+n);
        //f[i]表示 標準為i 時所需的次數
        for(int i=1;i<=a[n];i++)
            for(int j=1;j<=n;j++)
                f[i]=abs(a[j]-i);

        //for(int i=1;i<=a[n];i++)cout<<f[i]<<' ';

        for(int i=a[n];i>=1;i--)
			if(f[i]<=m){
				cout<<f[i];
				return 0;
  			}

    }
    return 0;
}
/*

5 8
-3 -1 2 2 7

*/
