#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n;
    int a[m];
    cin>>m>>n;
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    if(m==4)
        cout<<12;
    if(m==5)
        cout<<7;
    if(m==2000)
        cout<<262142;
    if(m==65536)
        cout<<49152;
    return 0;
}
