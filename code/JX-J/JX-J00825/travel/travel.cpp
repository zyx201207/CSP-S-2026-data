#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
map<char,int> ma;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    ma['A']=1;
    ma['B']=2;
    ma['C']=3;
    ma['D']=4;
    ma['F']=5;
    if(s1==s3){
        cout<<"1";
        int f=0;
        for(int i=0;i<3;i++){
            if(s2[i]>='0' and s2[i]<='9' and s2[i]!=s4[i])f=1;
        }
        if(f==0){
            cout<<"1";
            for(int i=0;i<3;i++){
                if(s2[i]>='A' and s2[i]<='Z' and ((ma[s2[i]]<=3 and ma[s4[i]]<=3) or (ma[s2[i]]>3 and ma[s4[i]]>3)))f=1;
            }
            if(f==1){
                cout<<"1";
                for(int i=0;i<3;i++){
                    if(s2[i]>='A' and s2[i]<='Z' and ((ma[s2[i]]==ma[s4[i]]+1) or (ma[s2[i]]+1==ma[s4[i]])))f=0;
                }
                if(f==0)cout<<"1";
                else cout<<"0";
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }

    return 0;
}
