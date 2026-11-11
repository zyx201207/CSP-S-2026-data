#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long a[1000];
    string b[100000];
    string d[100000];
    string c[26];
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            b[j]=c[i];
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=a[i];j++){
            d[i]=c[i];
        }
    }
    for(int i=1;i<=b.size()/2;i++){
        if(b[i]!=d[i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
