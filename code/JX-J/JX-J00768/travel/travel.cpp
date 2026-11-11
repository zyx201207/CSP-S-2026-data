#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2>>c3>>c4;
    if(c1[0]!=c3[0]||c1[1]!=c3[1])
    {
        cout<<"0000";
        return 0;
    }
    else{
        if(c2[0]!=c4[0]||c2[1]!=c4[1]){
            cout<<"1000";
            return 0;
        }
        else{
            int  s1=c2[2]-'A',s2=c4[2]-'A';
            if(s1==6) s1=5;
            if(s2==6) s2=5;
            bool f1=s1<3,f2=s2<3;
            if(f1^f2){
                cout<<"1100";
                return 0;
            }
            else{
                if(abs(s1-s2)>1){
                    cout<<"1110";
                    return 0;
                }
                else{
                    cout<<"1111";
                    return 0;
                }
            }
        }
    }
    return 0;
}
