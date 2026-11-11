#include <bits/stdc++.h>
using namespace std;
long long a,b;
string s1,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>s1>>b>>s2;
    if(a==b){
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            if(s1[2]>='D'&&s2[2]>='D'){
                cout<<1111;
                return 0;
            }else if(s1[2]<'D'&&s2[2]<'D'){
                int k=abs(s1[2]-s2[2]);
            if(k==1){
                cout<<1111;
                return 0;
            }else{
            cout<<1110;
            return 0;
            }
            }else{
            cout<<1100;
            return 0;
            }
        }else{
        cout<<1000;
        return 0;
        }
    }else{
    cout<<"0000";
    return 0;
    }
    return 0;
}
