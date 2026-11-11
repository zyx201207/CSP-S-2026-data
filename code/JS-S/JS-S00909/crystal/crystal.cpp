#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;
int a[N],n,m,js[N];

bool check(int aa){
    for(int i=1;i+aa-1<=n;i++){
        int j=i+aa-1;
        int co=a[j]*aa-js[j]+js[i-1];
        if(co<0)continue;
        if(co<=m)return 0;
    }
    return 1;
}
int bs(){
    int l=1,r=n,mid=(l+r)>>1;
    while(l!=r){
        if(r-l<=5){break;}
        mid=(l+r)>>1;
        if(check(a[mid])){
            r=mid;
        }
        else l=mid+1;
    }
    while(!check(l))l++;
    return l-1;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    js[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        js[i]=js[i-1]+a[i];
    cout<<bs();
    return 0;
}
