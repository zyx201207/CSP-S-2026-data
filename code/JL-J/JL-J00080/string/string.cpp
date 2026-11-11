#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,b=0,m[20005],s[20005];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m[i]>>s[i];
        b+=m[i];
    }
    int l=b,r=1,k=0;
    for(int i=1;i<=b/2;i++){
        if(s[r]!=s[l]){
            if(m[r]>m[l])k+=m[l];
            else k+=m[r];
        }
    }
    cout<<k;
    return 0;
}
