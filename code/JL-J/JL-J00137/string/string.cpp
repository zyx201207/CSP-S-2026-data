#include<bits/stdc++.h>
using namespace std;
string a;
int b[100086];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,zdjd=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int s;
        string p;
        cin>>s>>p;
        a+=p;
        b[zdjd]=s;
        zdjd++;
    }
    long long kskbl=0;
    for(int i=0;i<zdjd/2;i++){
        if(a[i]!=a[zdjd-i-1]){
            kskbl+=b[i];
        }
    }
    cout<<kskbl;
    return 0;
}
