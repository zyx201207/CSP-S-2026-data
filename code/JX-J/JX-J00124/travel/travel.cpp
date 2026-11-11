#include <bits/stdc++.h>
using namespace std;
struct stu{
    string c,p;
    char z,s[4];
};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    stu R,X;
    cin>>R.c>>R.s[1]>>R.s[2]>>R.z>>X.c>>X.s[1]>>X.s[2]>>X.z;
    if(R.c==X.c){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }if(R.s[1]==X.s[1]&&R.s[2]==X.s[2]){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }int s1=(int)R.z,s2=(int)X.z;
    if((s1<=67&&s2<=67)||(s1>67&&s2>67)){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }if(s1>67){
        cout<<1;
    }else if(s1-s2==1||s2-s1==1){
        cout<<1;
    }else cout<<0;
    return 0;
}
