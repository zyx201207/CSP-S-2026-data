#include<bits/stdc++.h>
using namespace std;
int num,numm,pai,paii,tmp,ans;
char c,cc,wei,weii;
string s,ss;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c>>cc;
    if(c=='1')num=10;
    num+=(int)(cc-'0');
    cin>>c>>cc>>wei;
    if(c=='1')pai=10;
    pai+=(int)(cc-'0');
    cin>>c>>cc;
    if(c=='1')numm=10;
    numm+=(int)(cc-'0');
    cin>>c>>cc>>weii;
    if(c=='1')paii=10;
    paii+=(int)(cc-'0');
    if(num!=numm){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if(pai!=paii){
        cout<<"000";
        return 0;
    }
    cout<<1;
    if((int)(wei-'A')<=2&&(int)(weii-'A')<=2||(int)(wei-'A')>=3&&(int)(weii-'A')>=3){
        cout<<1;
    }
    else{
        cout<<"00";
        return 0;
    }
    if(abs((int)wei-(int)weii)==1)cout<<1;
    else cout<<0;
    return 0;
}
