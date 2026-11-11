#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
bool solve1(){
    return s1==s3;
}
bool solve2(){
    char x=s2[0],xt=s4[0],y=s2[1],yt=s4[1];
    if(s1==s3&&x==xt&&y==yt)return 1;
    return 0;
}
bool solve3(){
    char x=s2[0],xt=s4[0],y=s2[1],yt=s4[1],z=s2[2],zt=s4[2];
    if(y!=yt||x!=xt)return 0;
    if(s1==s3&&x==xt&&y==yt&&(z=='F'&&zt=='D')||(zt=='F'&&z=='D')||(z=='C'&&zt=='B')||(z=='C'&&zt=='A')||(z=='B'&&zt=='C')||(z=='B'&&zt=='A')||(z=='A'&&zt=='C')||(z=='A'&&zt=='B'))return 1;
    return 0;

}
bool solve4(){
    char x=s2[0],xt=s4[0],y=s2[1],yt=s4[1],z=s2[2],zt=s4[2];
    if(y!=yt||x!=xt)return 0;
    if(s1==s3&&x==xt&&y==yt&&((z=='F'&&zt=='D')||(zt=='F'&&z=='D')||(z=='C'&&zt=='B')||(z=='C'&&zt=='A')||(z=='B'&&zt=='C')||(z=='B'&&zt=='A')||(z=='A'&&zt=='C')||(z=='A'&&zt=='B'))&&(abs(z-zt)==1)&&((z!='C'&&zt!='D')||(z!='D')||(zt!='C')))return 1;
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    cout<<solve1()<<solve2()<<solve3()<<solve4();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
