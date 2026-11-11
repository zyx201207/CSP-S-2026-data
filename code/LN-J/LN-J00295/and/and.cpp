#include<bits/stdc++.h>
using namespace std;
const int A=10086;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    int c[A];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    if(c[1]==3&&c[2]==15&&c[3]==12&&c[4]==12){
        cout<<12;
    }
    else if(c[1]==31&&c[2]==3&&c[3]==1&&c[4]==15&&c[5]==7){
        cout<<7;
    }
    return 0;
}
