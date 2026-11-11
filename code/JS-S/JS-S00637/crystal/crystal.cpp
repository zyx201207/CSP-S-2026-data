#include<bits/stdc++.h>

#define pcn putchar('\n');
#define pck putchar(' ');
#define int long long

using namespace std;
const int mod=998244353;

void free(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
}

int n,m,l=1,r=1,ans=1,p=0;
int a[500100];
signed main(){
    //scanf("%d",);
    //printf("%d",);
    free();
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        r++;
        p+=(r-l)*(a[r]-a[r-1]);
        if(p<=m){
            ans=max(ans,r-l+1);
            continue;
        }
        while(l<r&&p>m){
            l++;
            p-=(a[r]-a[l-1]);
            if(p<m) break;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
