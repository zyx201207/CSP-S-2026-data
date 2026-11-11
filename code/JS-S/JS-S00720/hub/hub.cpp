#include<bits/stdc++.h>
using namespace std;

//It's too hard.I can't make it.Give me a little score.
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>x>>y;
        if(x/y<3){
            cout<<"1"<<endl;
        }
        else if(x/y<5){
            cout<<"2"<<endl;
        }
        else{
            cout<<"3"<<endl;
        }
    }
    return 0;
}
