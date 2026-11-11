#include<bits/stdc++.h>

using namespace std;

string c1,s1,c2,s2;

int s11,s22;

int out[4]={0,0,0,0};

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){out[0]=true;}//1
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&out[0]==true){out[1]=true;}//2
    bool tmp1=((s1[2]>64&&s1[2]<68)&&(s2[2]>64&&s2[2]<68));
    bool tmp2=((s1[2]>67&&s1[2]<70)&&(s2[2]>67&&s2[2]<70));
    if(out[1]==true&&(tmp1||tmp2)){out[2]=true;}//3
    bool tmp3=(s1[2]=='D'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='D');
    if((s1[2]-s2[2]==1||s1[2]-s2[2]==-1)&&!tmp3&&out[1]==true){out[3]=true;}//4
    cout<<out[0]<<out[1]<<out[2]<<out[3];
return 0;
}
