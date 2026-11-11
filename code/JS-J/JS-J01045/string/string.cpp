#include<bits/stdc++.h>
using namespace std;
int a[200005],n;
string s;
long long f;
bool g=1;
char c[200005];
int main(){
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    cin>>n>>a[1]>>c[1];
    for(int i=2;i<=n;i++){
        cin>>a[i]>>c[i];
        f+=a[i];
        if(c[i]!=c[i-1]){
            g=0;
        }
    }if(g){cout<<0;}
    else{cout<<f/2;}

    return 0;
}
