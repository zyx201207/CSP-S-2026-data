#include<bits/stdc++.h>
using namespace std;
int n,m,a[600000],b[600000];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int s=0;
    for(int i=1;i<=n;i++){
        b[i]=a[n];
        s+=a[n]-a[i];
    }
    s=s-m;
    int j=n-1;
    int cn=0;
    while(cn<s){
        int c=a[j+1]-a[j];
        for(int i=1;i<=j;i++){
            b[i]=b[i]-c;
            cn=cn+c;
        }
        j--;
    }
    int ans=1;
    for(int i=1;i<=n;i++){
        if(b[i]==b[i+1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
