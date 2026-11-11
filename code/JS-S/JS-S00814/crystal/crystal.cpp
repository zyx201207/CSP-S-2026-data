#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int n,m,a[N],c[N],s[N],ans;
bool check(){
    int cha=a[2]-a[1];
    for(int i=2;i<n;i++){
        if(a[i+1]-a[i]!=cha){
            return false;
        }
    }
    int jian=cha;
    for(int i=1;i<n;i++){
        m-=jian;
        jian+=cha;
        if(m<=0){
            cout <<i;
            return true;
        }
    }
    cout <<n;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >>n>>m;
    for(int i=1;i<=n;i++){
        cin >>a[i];
    }
    sort(a+1,a+n+1);
    if(check()){
        return 0;
    }
    for(int i=1;i<=n;i++){
        c[i]=a[i]-a[1];
    }
    for(int i=2;i<=n;i++){
        s[i]=s[i-1]+c[i];
    }
    for(int i=2;i<=n;i++){
        for(int j=i-1;j>=1;j--){
            int res=c[i]*(i-j)-s[i-1]+s[j];
            if(res>m){
                break;
            }
            ans=max(ans,(i-j+1));
        }
    }
    cout <<ans;
    return 0;
}
