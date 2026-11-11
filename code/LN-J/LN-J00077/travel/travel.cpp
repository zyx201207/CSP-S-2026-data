#include <bits/stdc++.h>
using namespace std;

int f[4];
char a1[3],b1[5],a2[3],b2[5];

int main(){
    freopen("travel.in", "r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>b1>>a2>>b2;

    //同车厢?
    if(a1[0]==a2[0] && a1[1]==a2[1]) {
        f[0]=1;
        //同一排?
        if(b1[0]==b2[0] && b1[1]==b2[1]){
            f[1]=1;
            //同侧?
            if(f[1] && b1[2]>='A' && b1[2]<='C' && b2[2]>='A' && b2[2]<='C') f[2]=1;
            else if(f[1] && b1[2]>='D' && b1[2]<='F' && b2[2]>='D' && b2[2]<='F') f[2]=1;
        }
    }

    if(f[0] && f[1] && f[2] && !(b1[2]=='A' && b2[2]=='C') && !(b2[2]=='A' && b1[2]=='C')){
        f[3]=1;
    }

    for(int i=0;i<4;i++) cout<<f[i];

    /*test
    fcloseall();
    cout<<endl;
    freopen("travel1.ans","r",stdin);
    char ans[5]; cin>>ans;
    cout<<"Answer: "<<ans;
    */
    return 0;
}
