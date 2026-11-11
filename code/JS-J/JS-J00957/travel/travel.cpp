#include<bits/stdc++.h>
using namespace std;
int si(string x){
    int ans=0;
    for(int i=0;i<x.size();i++){
        ans=ans*10+(x[i]-'0');
    }
    return ans;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int r1=si(c1),x1=si(c2);
    string temp1,temp2;
    temp1=s1[0]+s1[1];
    temp2=s2[0]+s2[1];
    int r2=si(temp1),x2=si(temp2);
    char op1=s1[2],op2=s2[2];
    bool flag1=0,flag2=0,flag3=0,flag4=0;
    if(r1==x1){
        flag1=1;
        if(r2==x2){
            flag2=1;
            if((op1=='D'&&op2=='F')||(op1=='F'&&op2=='D')||(op1=='A'&&op2=='B')||(op1=='B'&&op2=='A')||(op1=='A'&&op2=='C')||(op1=='C'&&op2=='A')||(op1=='B'&&op2=='C')||(op1=='C'&&op2=='B')){
                flag3=1;
                if((op1=='D'&&op2=='F')||(op1=='F'&&op2=='D')||(op1=='A'&&op2=='B')||(op1=='B'&&op2=='A')||(op1=='B'&&op2=='C')||(op1=='C'&&op2=='B')){
                    flag4=1;
                }
            }
        }
    }
    cout<<flag1<<flag2<<flag3<<flag4;
    return 0;
}
