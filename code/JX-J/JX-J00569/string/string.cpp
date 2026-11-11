#include<bits/stdc++.h>
using namespace std;
string s;
char c[2000];
int n,x;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>c[i];
        for(int j=1;j<=x;j++){
            s+=c[i];
        }
    }
    cout<<s.size()/2;
    return 0;
}
