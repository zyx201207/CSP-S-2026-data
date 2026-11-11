#include<bits/stdc++.h>
using namespace std;
int a[20005];
int n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==2){
        int ans=INT_MIN;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                ans=max(ans,a[i]&a[j]);
        cout<<ans;
    }
    if(m==3){
        int ans=INT_MIN;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                for(int k=j+1;k<=n;k++)
                    ans=max(ans,a[i]&a[j]&a[k]);
        cout<<ans;
    }
    if(m==4){
        int ans=INT_MIN;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                for(int k=j+1;k<=n;k++)
                    for(int l=k+1;l<=n;l++)
                        ans=max(ans,a[i]&a[j]&a[k]&a[l]);
        cout<<ans;
    }
    if(m==5){
        int ans=INT_MIN;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                for(int k=j+1;k<=n;k++)
                    for(int l=k+1;l<=n;l++)
                       for(int x=l+1;x<=n;x++)
                        ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[x]);
        cout<<ans;

    }
    if(m==6){
        int ans=INT_MIN;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                for(int k=j+1;k<=n;k++)
                    for(int l=k+1;l<=n;l++)
                       for(int x=l+1;x<=n;x++)
                            for(int y=x+1;y<=n;y++)
                                ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[x]&a[y]);
        cout<<ans;
    }
    if(m==7){
        int ans=INT_MIN;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                for(int k=j+1;k<=n;k++)
                    for(int l=k+1;l<=n;l++)
                       for(int x=l+1;x<=n;x++)
                            for(int y=x+1;y<=n;y++)
                                for(int t=y+1;t<=n;t++)
                                    ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[x]&a[y]&a[t]);
        cout<<ans;
    }
    return 0;
}
