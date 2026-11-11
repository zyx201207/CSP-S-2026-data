#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>s>>cc>>ss;
    if(c!=cc){
        cout<<"0000";
        return 0;
    }
    if(!(s[0]==ss[0]&&s[1]==ss[1])){
        cout<<"1000";
        return 0;
    }
    int chs=int(s[2])-64,chss=int(ss[2])-64;
    if(chs>=1&&chs<=3&&chss>=4&&chss<=5||chss>=1&&chss<=3&&chs>=4&&chs<=5){
        cout<<"1100";
        return 0;
    }
    if(abs(chs-chss)!=1){
        cout<<"1110";
        return 0;
    }
    cout<<"1111";
    return 0;
}