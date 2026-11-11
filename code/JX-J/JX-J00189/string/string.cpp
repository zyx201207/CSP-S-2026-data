#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,s=0,ans=0,q=0,m;
    char a;
    string b;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m>>a;
        s+=m;
        for(int j=0;j<m;j++){
            b+=a;
        }
    }
    for(int i=0,j=s-1;i<s,j>=i;i++,j--){
        if(b[i]!=b[j]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
