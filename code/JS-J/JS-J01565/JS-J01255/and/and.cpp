#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,a[200005],ans=0,x;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        x=max(x,a[i]);
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            ans=max(ans,a[i]);
        }
        cout<<ans;
    }
    else if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
    }
    else if(m==n-1){
        ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
        for(int i=1;i<=n;i++){
            ans=max(ans,ans^a[i]);
        }
        cout<<ans;
    }
    else if(x<=4){
            ans=15;
        int aa[4]={0,0,0,0};
        for(int i=1;i<=n;i++){
            if(a[i]==1){
                aa[0]=1;
            }
            else if(a[i]==2){
                aa[1]=2;
            }
            else if(a[i]==3){
                aa[2]=3;
            }
            else{
                aa[3]=4;
            }
        }
        for(int i=0;i<4;i++){
            if(aa[i]!=0){
                ans=ans&aa[i];
            }
        }
        cout<<ans;
    }
    else{
        for(int i=1;i<=n;i++){
            ans=max(ans,a[i]);
        }
            cout<<ans;
    }
    return 0;
}

