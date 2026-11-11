#include<bits/stdc++.h>
using namespace std;
int ans=1;
int main()
{
    ios::sync_with_stdio();
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        for(int j=0;i<=n;j++){
            int a[j];
            sort(a,a+j+1);
            cin>>a[j];
        if(a[i]==a[i+1]){
            if(a[i]-a[i-1]<=m){
                ans+=1;
                while(a[i-1]==a[i]){
                    a[i-1]++;
                }
                m-=a[i]-a[i-1];
            }
        }
        else{
            if(a[i+1]-a[i]<=m){
                ans+=1;
                while(a[i]==a[i+1]){
                    a[i]++;
                }
                m-=a[i+1]-a[i];
            }
        }
        }
    }
    cout<<ans;
    freopen("crystal.out","w",stdout);
    return 0;
}
