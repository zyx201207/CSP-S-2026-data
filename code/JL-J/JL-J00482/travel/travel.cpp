#include <bits/stdc++.h>
using namespace std;
string a,b,n,m;
int x1=0,x2=0,x3=0,x4=0;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
    cin>>a>>b>>n>>m;
    if(a[0]==n[0]&&a[1]==n[1]){
        x1=1;
        if(b[0]==m[0]&&b[1]==m[1]){
            x2=1;
            if((b[2]<='C'&&m[2]<='C')||(b[2]>='D'&&m[2]>='D')){
                x3=1;
                if(b[2]-'B'+'A'==m[2]||m[2]-'B'+'A'==b[2]){
                    x4=1;
                    cout<<x1<<x2<<x3<<x4;
                }
                else cout<<x1<<x2<<x3<<x4;
            }
            else cout<<x1<<x2<<x3<<x4;
        }
        else cout<<x1<<x2<<x3<<x4;
    }
    else cout<<x1<<x2<<x3<<x4;
}
