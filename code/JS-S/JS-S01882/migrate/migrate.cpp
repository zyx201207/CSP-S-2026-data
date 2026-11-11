#include<bits/stdc++.h>
using namespace std;
#define int long long
#define SZ(a) (int)(a.size())
#define pb push_back
#define mk make_pair
const int N=2e6+5;
const int inf=1e9+7;
int c,n,d;
int a[N];
int cnt=0,minn=inf;
void dg(int pos,int end,int num){
    if(pos==end){
        if(num<minn){
            cnt=1;
            minn=num;
        }
        else if(num==minn){
            cnt++;
        }
        return;
    }
    for(int i=pos+1;i<=end;i++){
        if(a[i]-a[pos]<=d)dg(i,end,num+1);
        else break;
    }
}
int check(int beg,int end){
    cnt=0;
    minn=inf;
    dg(beg,end,0);
    if(cnt==2)return 1;
    return 0;
}
void solve(){
    int ans=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int l=1;l<=n;l++){
        for(int r=l+3;r<=n;r++){
            ans+=check(l,r);
        }
    }
    cout<<ans<<'\n';
}
bool check2(int qw,int we,int er,int rt){
    if(a[er]-a[qw]<=d&&a[rt]-a[we]<=d&&a[rt]-a[qw]>d)return 1;
    return 0;
}
int js2(int lef,int rig){
    int ptl=lef-1,ptr=rig+1;
    if(lef!=1&&a[lef+1]-a[lef-1]>d&&a[lef]-a[lef-1]<=d){
        while(ptl>=1){
            if(a[ptl]-a[ptl-1]>d)break;
            if(a[ptl+1]-a[ptl-1]<=d)break;
            ptl--;
        }
    }
    ptl++;
    if(rig!=n&&a[rig+1]-a[rig-1]<d&&a[rig+1]-a[rig-1]<=d){
        while(ptr<=n){
            if(a[ptr]-a[ptr-1]>d)break;
            if(a[ptr+1]-a[ptr-1]<=d)break;
            ptr++;
        }
    }
    ptr--;
    return (lef-ptl+1)*(ptr-rig+1);
    
}
void solve2(){
    int ans=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int l=1;l<=n;l++){
        if(check2(l,l+1,l+2,l+3)){
            ans+=js2(l,l+4);
        }
    }
    cout<<ans<<'\n';
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int T;
    cin>>c>>T;
    if(c<=2)while(T--)solve();
    else while(T--)solve2();
    return 0;
}