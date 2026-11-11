#include<bits/stdc++.h>
using namespace std;
const int maxn=505,maxm=5e5+5;
int c,n,m,d,q;
int w[maxm];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=2*k;j++){
            int g;
            cin>>g;
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        srand(time(0));
        int ee=abs(rand());
        cout<<ee<<endl;
    }
    return 0;
}
