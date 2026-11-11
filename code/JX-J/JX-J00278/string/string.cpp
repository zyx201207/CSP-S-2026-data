#include<bits/stdc++.h>
using namespace std;
int n,b,s=0,d=0;
char c,a[200005];
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b>>c;
        for(int j=1;j<=b;j++){
            s++;
            a[s]=c;
        }
    }
    for(int i=1;i<=s/2;i++){
        if(a[i]!=a[s+1-i])d++;
    }
    cout<<d;
    return 0;
}
