#include<bits/stdc++.h>
#define int long long
using namespace std;
string ss1,ss2,cc1,cc2;
char ma,mi;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>ss1>>cc1>>ss2>>cc2;
    ma=max(cc1[2],cc2[2]),mi=min(cc2[2],cc1[2]);
    if(ss1[0]!=ss2[0]||ss1[1]!=ss2[1]){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if(cc1[0]!=cc2[0]||cc1[1]!=cc2[1]){
        cout<<"000";
        return 0;
    }
    cout<<1;
    if(ma>='D'&&mi<='C'){
        cout<<"00";
        return 0;
    }
    cout<<1;
    if(ma-mi!=1&&(ma!='F'&&mi!='D')){
        cout<<"0";
        return 0;
    }
    cout<<1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
