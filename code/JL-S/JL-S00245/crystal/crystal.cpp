#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int amo;
    int w;
};
int n,m;
int a[500005];
int c[500005];
int d[500005];
int d2[500005];
bool cmp(int x,int y){
    return x>y;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //choose the closest
    //most
    sort(a+1,a+1+n,cmp);
    //1   ->  1~2
    for(int i=1;i<n;i++){
        c[i]=a[i]-a[i+1];
    }

    for(int i=1;i<n;i++){
        d[i]=c[i]+d[i-1];
    }
    for(int i=1;i<n;i++){
        d[i]+=d[i-1];
    }

    int ans=0;
    int ku1=0,ku2=0;
    for(int i=1;i<n;i++){
        int l=i,r=n;
        //find m
        while(l<r){
            int mid=(l+r)/2;
            if(d[mid]-ku1*mid+ku2>=m){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        if(d[l]-ku1*l+ku2==m){
            ans=max(ans,l-i+2);
        }
        else{
            ans=max(ans,l-i+1);
        }
        ku1+=d[i];
        ku2+=(i-1)*d[i];

    }
    cout<<ans;
    return 0;
}

