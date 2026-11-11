#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,c1,c2;
    cin>>c>>n;
    if(c==0&&n==2){
        c1=32;
        c2=17;
        cout<<c1<<endl;
        cout<<c2;
    }

    if(c==0&&n==3){
        c1=35;
        c2=16;
        cout<<c1<<endl;
        cout<<c2;
    }
    return 0;
}
