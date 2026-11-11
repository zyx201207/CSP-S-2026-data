#include<bits/stdc++.h>
using namespace std;
using ll=long long;
map<char,int> mp;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    mp['A']=1;
    mp['B']=1;
    mp['C']=1;
    mp['D']=2;
    mp['F']=2;
    if(s1==s3){
        cout<<"1";
        if(s2[1]==s4[1]&&s2[0]==s4[0]){
            cout<<"1";
            if(mp[s2[2]]==mp[s4[2]]){
                cout<<"1";
                if(mp[s2[2]]==2||abs((int)(s4[2]-s2[2]))==1){
                    cout<<"1";
                }else{
                    cout<<"0";
                }
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