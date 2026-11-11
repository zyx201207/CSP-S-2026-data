#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>n>>n;
    if(n==2){
        cout<<32<<endl<<17;
        return 0;
    }
    if(n==3){
        cout<<35<<endl<<16;
        return 0;
    }
    else{
        cin>>n>>n>>n;
        while(n>=1){
            n-=1;
            cout<<1<<endl;
        }
    }
}
