#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }else{
        if(s1.substr(0,2)!=s2.substr(0,2)){
            cout<<"1000";
            return 0;
        }else{
            if(!((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='E'&&s2[2]>='D'&&s2[2]<='E'))){
                cout<<"1100";
                return 0;
            }else{
                int a=s1[2],b=s2[2];
                if(abs(a-b)!=1){
                    cout<<"1110";
                    return 0;
                }else{
                    cout<<"1111";
                    return 0;
                }
            }
        }
    }
    return 0;
}
