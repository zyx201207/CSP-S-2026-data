#include<bits/stdc++.h>
using namespace std;
int n,m;

struct s{
   int g;
   int l=0;
}p[1000001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","r",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>p[i].g;
    }
    cout<<p[3].g;
    return 0;
}
