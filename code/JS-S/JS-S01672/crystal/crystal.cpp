#include<bits/stdc++.h>//15:33 i finish T1 75pts
using namespace std;//think std later
#define int long long//after T3 i back,but failed
const int N=5e5+5;
int n,m,a[N],sum=0;
bool cmp(int x,int y){
    return x>y;
}
void solB(int del){//30pts
    int s=0,cnt=1,mx=0;
    for(int i=n;i>1;i--){
        if(s+del<=m){
            s+=del;
            del+=del;
            cnt++;
        }
        else{
            break;
        }
    }
    cout<<cnt<<"\n";
}
signed main(){//O(n^2)baoli,45pts
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    bool flB=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
        if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])flB=0;
    }
    sort(a+1,a+n+1,cmp);
    if(m>=a[1]*n-sum){
        cout<<n<<"\n";
        return 0;
    }
    if(flB){
        solB(a[1]-a[2]);
        return 0;
    }
    int p=1,mx=0,cnt=0;
    for(int i=1;i<n;i++){
        int k=0;
        cnt=1;
        for(int j=i+1;k+a[i]-a[j]<=m&&j<=n;j++){
            k+=a[i]-a[j];
            cnt++;
        }
        mx=max(mx,cnt);
    }
    cout<<mx<<"\n";
    return 0;
}
/* wish all RP++!!!
remember:
1,if "freopen" is not in "//"
2,if clear with T
3,if folder is named in a correct way
4,if "return 0" in "main()" or int-like
5,if view the problems correctly
  e.g. n<=?,A,B?,mod=?
6,try the examples by hands and PC

18:05 i dont want to do it anymore
i even dont know how to solve T1,3 basic points
i ll get 83pts,and yi han li chang
if someone see this,my luoguID is _wisadel_
its my first time to arrive CSP-S2,maybe also the last time
if i pass,i ll seriously study to make up my tu lun
    WHY CSP-S2 SO TIREING???
    WHY SOMEONE IS ALWAYS SINGING???
*/
