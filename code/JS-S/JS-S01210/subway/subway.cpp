#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    int s=0;
    for(int i=0;i<m;i++){
        cin>>w[i];
        s+=w[i];
    }
    cout<<s;
    return 0;
}
