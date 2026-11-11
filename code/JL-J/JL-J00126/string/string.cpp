#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N];
char c[N];
bool ok=1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        if(i>=2){
            if(c[i]!=c[i-1]) ok=0;
        }
    }
    if(ok){
        cout<<0;
        return 0;
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    if(n<=2){
        if(c[1]!=c[2]) cout<<min(a[1],a[2]);
        else cout<<0;
        return 0;
    }
    cout<<a[1];
    return 0;
}
