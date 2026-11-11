#include<bits/stdc++.h>
using namespace std;
string m,x;
int main(){
    /*ios::sync.stdio;
    cin.tie(0);
    cout.tie(0);*/
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a,b=1;
    char c;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int j=1;i<=a;j++){
            m[j]=c;
        }
    }
    for(int i=n*a;i>=1;i--){
        x[b]=m[i];
        b++;
    }
    if(x==m){
        cout<<0;
        return 0 ;
    }
    return 0;
}
