#include<bits/stdc++.h>
using namespace std;
int t[100000000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n,b,d=0;
    cin>>m>>n;
    t[0]=0;
    for(int i=1;i<=m;i++){
        cin>>t[i];
    }
    cout<<t[m-1];
    return 0;
}
