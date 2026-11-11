#include<bits/stdc++.h>
using namespace std;
long long r,x,r1,x1;
string r2,x2,ans="0000";
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r>>r1>>r2>>x>>x1>>x2;
    if(r==x){
        ans[0]='1';
        if(r1==x1){
            ans[1]='1';
            if((r2=="A" or r2=="B" or r2=="C") and (x2=="A" or x2=="B" or x2=="C")){
                ans[2]='1';
                if((r2=="A" and x2=="B") or (r2=="B" and x2=="A") or (r2=="C" and x2=="B") or (r2=="B" and x2=="C")){
                    ans[3]='1';
                }
            }
            if((r2=="E" or r2=="D") and (x2=="E" or x2=="D")){
                ans[2]='1';
                ans[3]='1';
            }
        }
    }
    cout<<ans;
    return 0;
}
