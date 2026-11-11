#include<iostream>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    bool flag1=0,flag2=0,flag3=0;
    if(c1==c2) {
        cout<<1;
        flag1=1;
    }
    else cout<<0;
    if(flag1==1&&s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<1;
        flag2=1;
    }
    else cout<<0;
    if(flag1==1&&flag2==1&&((s1[2]<=65&&s2[2]<=65)||(s1[2]>65&&s2[2]>65)){
        cout<<1;
        flag3=1;
    }
    else cout<<0;
    if(flag1==1&&flag2==1&&flag3==1&&(s1[2]+1==s2[2]||s1[2]-1==s2[2]))cout<<1;
    else cout<<0;

    return 0;
}
