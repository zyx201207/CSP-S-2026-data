#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    int t1=(s1[0]-'0')*10+s1[1]-'0';
    int t2=(s2[0]-'0')*10+s2[1]-'0';
    int t3=(s3[0]-'0')*10+s3[1]-'0';
    int t4=(s4[0]-'0')*10+s4[1]-'0';
    string ans;
    if(t1==t3){
        ans+='1';
    }
    else{
        ans+='0';
    }
    if((t2==t4)&&(t1==t3)){
        ans+='1';
    }
    else{
        ans+='0';
    }
    int x1=(s2[2]-'A');
    int x2=(s4[2]-'A');
    if(((x1>=3)&&(x2>=3)||(x1<3)&&(x2<3))&&(t2==t4)&&(t1==t3)){
        ans+='1';
    }
    else{
        ans+='0';
    }
    if(((x1==0&&x2==1)||(x1==1&&x2==2)||(x1==3&&x2==4))&&(t2==t4)&&(t1==t3)){
        ans+='1';
    }
    else{
        ans+='0';
    }
    cout<<ans;
    return 0;
}

