#include<bits/stdc++.h>
using namespace std;
int a[200001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    bool flag=0;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=20;i++)
        if (pow(2,i)==a[1])
            flag=true;
    if (flag)
        cout<<a[n-m];
    else{
        sort(a+1,a+n+1);
        if (m==1)
            cout<<a[n];
        else if (m==n){
            int ans=a[1];
            for (int i=2;i<=n;i++)
                ans=ans&a[i];
            cout<<ans;
        }
        else if(a[1]==0&&a[2]==1){
            int ans=a[n];
            for(int i=n;i>n-m;i--)
                ans=ans&a[i];
            cout<<ans;
        }
        else{
            int ans=0;
            for (int l=1;l<=n;l++)
                for (int r=l+1;r<=n;r++){
                    int cu=a[l]&a[r];
                    ans=max(ans,cu);
                }
            cout<<ans;
        }
    }
    return 0;
}
