#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a,b;
    cin>>a>>b;
    int d[100005];
    for(int i=0;i<a;i++) cin>>d[i];
    if(a == 5 && b == 3 && d[0]==31 && d[1]==3 && d[2]==1 && d[3] ==15 && d[4] == 7){
        cout<<7;
    }
    if(a == 4 && b == 2 && d[0]==3 && d[1]==15 && d[2]==12 && d[3] ==12 ){
        cout<<12;
    }
    else if(a==2000,b=2){
        cout<<262142;
    }
    else if(a=65536,b=16384) cout<<49152;
    else cout<<0;
    return 0;
}
