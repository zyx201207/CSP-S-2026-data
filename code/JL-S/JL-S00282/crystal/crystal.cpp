#include<bits/stdc++.h>
using namespace std;
int n,ans,b[500005],c;
long long m,a[50005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n-1);
    for(int i=0;i<n;i++)b[a[i]]++,c=c+a[i+1]-a[i];
    c+=a[n-1];
    if(m>=c){
        cout<<n;
        return 0;
    }
    if(m==0){
        for(int i=0;i<n-1;i++){
            if(a[i]==a[i+1])ans++;
        }
        cout<<ans+1;
        return 0;
    }
    int j=0;
    if(b[a[n/2]]<b[a[n/2]+1])j++;
    else if(b[a[n/2]]<b[a[n/2]+1])j--;
    while(a[n/2]!=a[n/2+j])j++;
    for(int i=n/2+j;i>=0;i--){
        m-=(a[n/2]-a[i]);
        if(m<0){
            cout<<ans;
            return 0;
        }
        ans++;
    }
    if(m){
        for(int i=n/2;i<n;i++){
            if(a[i]>a[n/2]){
                cout<<ans;
                return 0;
            }
            m-=(a[n/2]-a[i]);
            if(m<0){
                cout<<ans;
                return 0;
            }
            ans++;
        }
    }
    cout<<ans+1;
    return 0;
}
