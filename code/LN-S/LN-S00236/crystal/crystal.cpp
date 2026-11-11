#include<bits/stdc++.h>
using namespace std;
#define int long long
int cmp(int a,int b){
    return a>b;
}
int a[500010],head,cnt;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=1,r=n,x=(a[1]+a[n])/2;
    while(l<r){
        int mid=(l+r)/2;
        if(a[mid]==x){
            head=a[mid];
            break;
        }else if(a[mid]>x){
            r=mid-1;
        }else{
            l=mid;
        }
    }
    if(a[r]<x){
        r++;
    }else{
        l--;
    }
    if(!head){
        int nearplacel=n-l;
        int nearplacer=r-1;
        if(nearplacel>nearplacer){
            head=a[r];
        }else{
            head=a[l];
        }
    }
    for(int i=1;i<=n;i++){
        a[i]=abs(a[i]-head);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        m-=a[i];
        if(m<0){
            break;
        }
        cnt++;
    }
    cout<<cnt;
}
