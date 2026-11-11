#include<bits/stdc++.h>
using namespace std;
int xiao_r,xiao_x;
string xiao_r_sit,xiao_x_sit,ans = "0000";
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>xiao_r>>xiao_r_sit>>xiao_x>>xiao_x_sit;

    int chazhi = abs(xiao_x_sit[2]-xiao_r_sit[2]);

    if(xiao_r==xiao_x){
        ans[0]='1';
    }

    if(ans[0]=='1' and xiao_x_sit[0]==xiao_r_sit[0] and xiao_x_sit[1]==xiao_r_sit[1]){
        ans[1]='1';
    }

    if(ans[1]=='1' and ((xiao_r_sit[2]>='A' and xiao_r_sit[2]<='C' and xiao_x_sit[2]>='A' and xiao_x_sit[2]<='C') or (xiao_r_sit[2]>='D' and xiao_r_sit[2]<='F' and xiao_x_sit[2]>='D' and xiao_x_sit[2]<='F'))){
        ans[2]='1';
    }

    if(ans[2]=='1' and chazhi == 1){
        ans[3]= '1';
    }else if(ans[2]=='1' and chazhi == 2 and xiao_r_sit[2]>='D' and xiao_x_sit[2]>='D'){
        ans[3] = '1';
    }

    cout<<ans;

    return 0;
}
