#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    int w,sumw;
    for(int i=1;i<=m;i++){
        cin>>w;
        sumw+=w;
    }
    int qiu;
    srand(qiu);
    for(int i=1;i<=q;i++)cout<<abs(rand()%sumw)+5<<'\n';
    return 0;
}
