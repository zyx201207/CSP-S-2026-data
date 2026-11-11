#include <bits/stdc++.h>
#define int long long
const int N=2e5+5;
int num[N][2];
using namespace std;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int tol=0;
    for(int i=0;i<n;i++){
        int a,b1;
        char b;
        cin>>a>>b;
        b1=(int)(b-'a');
        num[i][0]=a;
        num[i][1]=b1;
        tol+=a;
    }
    int l=0,lc=0,r=n-1,rc=num[n-1][0],ans=0;
    int now=0;
    while(now<tol){
        int maxn=min(num[l][0]-lc,rc);
        if(num[l][1]!=num[r][1]) ans+=maxn;
        lc+=maxn;
        rc-=maxn;
        now+=maxn;
        if(lc>=num[l][0]){
            l++;
            lc=0;
        }
        if(rc<=0){
            r--;
            rc=num[r][0];
        }
    }
    cout<<ans/2;
return 0;
}
