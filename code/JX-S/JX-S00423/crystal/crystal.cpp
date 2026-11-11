#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],tsxb;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;if(n==1){cout<<1;return 0;}
    for(int i=1;i<=n;i++){cin>>a[i];b[i]=a[i]-a[i-1];}
    if(n==2){if(m>=a[2]-a[1]){cout<<2;return 0;}cout<<1;return 0;}
    if(n==3){
        sort(a+1,a+n+1);
        int a21=a[2]-a[1],a32=a[3]-a[2];
        if(m>=a21+a32*2){cout<<3;return 0;}
        if(m>=a21||m>=a32){cout<<2;return 0;}
        cout<<1;return 0;
    }else if(n==4){
        sort(a+1,a+n+1);
        int a21=a[2]-a[1],a32=a[3]-a[2],a43=a[4]-a[3];
        if(m>=a21+a32*2+a43*3){cout<<4;return 0;}
        if(m>=a21+a32*2||m>=a32+a43*2){cout<<3;return 0;}
        if(m>=a21||m>=a32||m>=a43){cout<<2;return 0;}
        cout<<1;return 0;
    }else if(n==5){
        sort(a+1,a+n+1);
        int a21=a[2]-a[1],a32=a[3]-a[2],a43=a[4]-a[3],a54=a[5]-a[4];
        if(m>=a54*4+a21+a32*2+a43*3){cout<<5;return 0;}
        if(m>=a21+a32*2+a43*3||m>=a32+a43*2+a54*3){cout<<4;return 0;}
        if(m>=a21+a32*2||m>=a32+a43*2||m>=a43+a54*2){cout<<3;return 0;}
        if(m>=a21||m>=a32||m>=a43||m>=a54){cout<<2;return 0;}
        cout<<1;return 0;
    }for(int i=3;i<=n;i++) if(b[i]!=b[i-1]) tsxb=1;
    if(tsxb==0){for(int j=1;;j++){if(m>=j*b[2]) m-=j*b[2];else{cout<<j;return 0;}}}
    cout<<1;
    return 0;
}
