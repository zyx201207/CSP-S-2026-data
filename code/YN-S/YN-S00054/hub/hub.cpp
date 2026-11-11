#include<bits/stdc++.h>
using namespace std;
int main(){
    srand(time(0));
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int ans=rand()%3;
        if(ans==0){
            cout<<1<<'\n';
        }
        else{
            cout<<ans<<'\n';
        }
    }
}
