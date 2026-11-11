#include<bits/stdc++.h>
using namespace std;
int a,s;
string d="",f;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>s>>f;
        for(int j=1;j<=s;j++)
            d+=f[0];
    }
    f="";
    long long q=d.size(),cnt=0;
    for(int i=q-1;i>=0;i--)
        f+=d[i];
        for(int i=0;i<q;i++)
            if(f[i]!=d[i])
            cnt++;
        cout<<cnt/2;
    return 0;
}
