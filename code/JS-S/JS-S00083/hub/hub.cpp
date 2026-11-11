#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
typedef long long ll;

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cout<<rand()*t*c%2013<<endl;
    }
    return 0;
}
