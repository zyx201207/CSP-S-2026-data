#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    if(a1!=b1){
        cout<<"0000";
        return 0;
    }
    else{
        if((a2[0]==b2[0])&&(a2[1]==b2[1])){
            if((a2[2]<='C'&&a2[2]>='A'&&(b2[2]=='D'||b2[2]=='F'))||((a2[2]=='F'||a2[2]=='D')&&b2[2]>='A'&&b2[2]<='C')){
                cout<<"1100";
                return 0;
            }
            else{
                char x,y;
                x=a2[2],y=b2[2];
                int l,r;
                l=a2[2],r=b2[2];
                if((x=='D'&&y=='F')||(x=='F'&&y=='D')) cout<<"1111";
                else if((l==r+1)||(r==l+1)) cout<<"1111";
                else cout<<"1110";
                return 0;
            }
        }
        else{
            cout<<"1000";
            return 0;
        }
    }
    return 0;
}
