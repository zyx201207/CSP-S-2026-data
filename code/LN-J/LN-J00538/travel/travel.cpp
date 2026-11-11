#include <bits/stdc++.h>
using namespace std;
string x1,w1,x2,w2,d="0000";
int xiang,pai,ce,lin;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>x1>>w1>>x2>>w2;
    if(x1==x2){
        d[0]='1';
        if(w1[0]==w2[0]&&w1[1]==w2[1]){
            d[1]='1';
            if(w1[2]<'D'&&w2[2]<'D'){
                d[2]='1';
            }
            if(w1[2]>='D'&&w2[2]>='D'){
                d[2]='1';
            }
            if(((w1[2]-w2[2]==1)||(w1[2]-w2[2]==-1))&&d[2]=='1'){
                d[3]='1';
    }
    }
    }

    for(int i=0;i<=3;i++){
        cout<<d[i];
    }
    return 0;
}
