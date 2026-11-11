#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005],ans;
string b[100005];
bool x;
int main()
{
    freopen("string.in","r","stdin");
    freopen("string.out","w","stdout");
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        ans+=a[i];
    }
    string s=b[1];
    for(int i=1;i<=n;i++){
        if(b[i]!=s) x=true;
    }
    if(x==false) cout<<0;
    else cout<<ans/2;
    return 0;
}

