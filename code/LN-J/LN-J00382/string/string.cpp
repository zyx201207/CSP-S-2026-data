#include <bits/stdc++.h>
using namespace std;
int n,ans;
string a,d;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int b;
    string c;
    for(int i=1;i<=n;i++){
        cin>>b>>c;
        for(int j=1;j<=b;j++){
            a+=c;
        }
    }
    int q=a.size()-1;
    for(int i=0;i<a.size();i++){
    d[q--]=a[i];
    }
    for(int i=0;i<a.size();i++){
        if(a[i]!=d[i]){
        ans++;}
    }
    cout<<ans/2;
    return 0;

};
