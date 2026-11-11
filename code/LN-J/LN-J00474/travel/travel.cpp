#include<bits/stdc++.h>
using namespace std;
string r_c,r_z,x_c,x_z;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r_c>>r_z>>x_c>>x_z;
    bool tc=0,tp=0,tce=0,xl=0;
    if(r_c==x_c){
        tc=1;
    }if(r_z[0]==x_z[0]&&r_z[1]==x_z[1]&&tc==1){
        tp=1;
    }if((r_z[2]=='C'&&x_z[2]=='D')||(r_z[2]=='D'&&x_z[2]=='C')&&tc==1&&tp==1){
        tce=0;
    }else if(abs(r_z[2]-x_z[2])!=1&&tc==1&&tp==1){
        tce=1;
        xl=0;
    }else if((r_z[2]-x_z[2]==1||r_z[2]-x_z[2]==-1)&&tc==1&&tp==1){
        tce=1;
        xl=1;
    }
    cout<<tc<<tp<<tce<<xl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
