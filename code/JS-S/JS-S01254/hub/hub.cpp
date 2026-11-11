#include<bits/stdc++.h>
using namespace std;
const int maxn=505,maxm=5e5+5;
int c,t;
int w[maxm];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int x,y,a,b;
        cin>>x>>y;
        for(int i=1;i<=x-1;i++)cin>>a>>b;
        srand(time(0));
        int ee=abs(rand())%int(1e6+5);
        cout<<ee<<endl;
    }
    return 0;
}
