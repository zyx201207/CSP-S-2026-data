#include <bits/stdc++.h>
using namespace std;
struct p{
    string train;
    string seat;
}X,R;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string ans;
    cin>>X.train>>X.seat>>R.train>>R.seat;
    int xh=X.seat[2]-'A'+1,rh=R.seat[2]-'A'+1,xl,rl;
    xl=(X.seat[0]-'0')*10+X.seat[1]-'0';
    rl=(R.seat[0]-'0')*10+R.seat[1]-'0';
    if(X.train == R.train){
        ans[0]='1';
        if(xl==rl){
        ans[1]='1';
            if((xh<=3 && rh<=3)||(xh>=4 && rh>=4)){
                ans[2]='1';
                if(xh-rh==1 || rh-xh==1){
                    ans[3]='1';
                }else{
                    ans[3]='0';
                }
            }else{
                ans[2]='0';
            }
        }else{
            ans[1]='0';
        }

    }else{
        ans[0]='0';
    }
    for(int i=0;i<=3;i++)cout<<ans[i];
    return 0;
}

