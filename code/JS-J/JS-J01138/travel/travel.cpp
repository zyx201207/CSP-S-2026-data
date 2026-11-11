#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b;
    int n,m;
    cin>>n>>a>>m>>b;
    if(n!=m){
        cout<<"0000"<<endl;
        return 0;
    }
    cout<<1;
    string x=a.substr(0,2),y=b.substr(0,2);
    if(x!=y){
        cout<<"000"<<endl;
        return 0;
    }
    cout<<1;
    bool r=(a[2]<='C');
    bool t=(b[2]<='C');
    if(r!=t){
        cout<<"00"<<endl;
        return 0;
    }
    cout<<1;
    if(abs(a[2]-b[2])!=1){
        cout<<"0"<<endl;
        return 0;
    }
    cout<<1;
    return 0;
}

// T1,20min
// Lets goooooooooooooooooooooooooooo!


// ccf,i love you:
// i love three things in the world
// the sun,the moon,and ccf;
// i love the sun for days
// the moon for nights
// and ccf forever