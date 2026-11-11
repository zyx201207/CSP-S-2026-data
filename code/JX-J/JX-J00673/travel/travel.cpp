#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string flag="0000";
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        flag[0]='1';
        string x1="",x2="";
        x1=s1.substr(0,2);
        x2=s2.substr(0,2);
        if(x1==x2){
            flag[1]='1';
            char y1=s1[2],y2=s2[2];
            if((y1>='A'&&y1<='C'&&y2>='A'&&y2<='C')||(y1>='D'&&y2>='D')){
                flag[2]='1';
                int sum=abs(int(y1)-int(y2));
                if(sum==1||(y1=='D'&&y2=='F')||(y1=='F'&&y2=='D')){
                    flag[3]='1';
                }
            }
        }
    }
    cout<<flag;
    return 0;
}
