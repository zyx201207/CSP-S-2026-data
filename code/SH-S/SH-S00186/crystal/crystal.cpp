#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,l,r,ans=-1;
    cin>>n>>m;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a.begin(),a.end());
    b[0]=0;
    for(int i=1;i<n;i++)
        b[i]=b[i-1]+i*(a[i]-a[i-1]);
    l=0,r=n-1;
    while(l<r){
        if(m>b[(l+r)/2])
            l=l+r/2;
        else if(m<b[(l+r)/2])
            r=(l+r)/2-1;
        else{
            ans=(l+r)/2+1;
            break;
        }
    }
    if(ans!=-1){
        while(ans!=n&&a[ans-1]==a[ans])
            ans++;
        cout<<ans;
    }
    else{
        while(l!=n-1&&a[l]==a[l+1])
            l++;
        cout<<l+1;
    }
    return 0;
}
