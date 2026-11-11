#include<bits/stdc++.h>
using namespace std;
long long n,a[100086],cnt;
char c[100086];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    bool t=0;
    for(int i=1;i<=n;i++){
        if(c[i]!=c[i-1]){
            t=0;
        }
        else t=1;
    }
    if(t){
        cout<<0;
        return 0;
    }
    if(n%2==0){
        cnt+=a[n];
    }
    if(c[1] != c[n]){
        cnt+=a[n];
    }
    if(a[1]!=a[n]){
        cnt+=abs(a[1]-a[n]);
    }
    cout<<cnt;
    return 0;
}
