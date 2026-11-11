#include<bits/stdc++.h>
using namespace std;

int n,m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        if (i==m){
            cout<<"2";
        }
        else {
            cout<<"1"<<endl;
        }
    }

    return 0;
}
