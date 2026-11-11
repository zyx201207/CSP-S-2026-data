#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    long long a[n+5];
    string c[n+5];
    string S,z;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        z=c[i];
        for(int j=1;j<=a[i];j++){
            S+=z;
        }
    }
    int k=S.size();
    int x=0;
    for(int i=0;i<=k/2;i++){
        if(S[i]!=S[k-1-i]){
            x++;
        }
    }
    cout<<x;
    return 0;
}
