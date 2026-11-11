#include<bits/stdc++.h>
using namespace std;
int main(){
    srand(time(0));
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        cout<<d*4-n-rand()%10+1+rand()%10+1+rand()%(n-1)+1-(rand()%r-3)<<"\n";
    }
    return 0;
}
