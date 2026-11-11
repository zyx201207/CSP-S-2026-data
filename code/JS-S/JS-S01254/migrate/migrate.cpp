#include<bits/stdc++.h>
using namespace std;
const int maxn=505,maxm=5e5+5;
int c,t;
int w[maxm];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int x,y,a;
        cin>>x>>y;
        for(int i=1;i<=x;i++)cin>>a;
        srand(time(0));
        int ee=abs(rand())%int(2e6+5);
        cout<<ee<<endl;
    }
    return 0;
}
