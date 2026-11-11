#include<bits/stdc++.h>
using namespace std;
long long a,m,n,d[10000]={0},z1,z2,z3;
string s;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a;
        if(z1<a){
            z1=a;
        }
        else if(z2<a){
            z2=a;
        }
        else if(z3<a){
            z3=a;
        }
    }
    cout<<max(z3&z2,max(z1&z2,z1&z3));
    return 0;
}
