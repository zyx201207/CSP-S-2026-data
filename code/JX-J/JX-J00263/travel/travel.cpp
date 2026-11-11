#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string p1,p2,q1,q2;
int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c1>>s1>>c2>>s2;
    //for(int i=4;i>=1;i--){
        if(c1==c2){
            cout<<1;
        }else{
            cout<<0;
        }
        for(int i=1;i<=4;i++){
            if(s1==p1&&s2==p2&&s1==q1&&s2==q2&&c1==p1&&c2==q2&&c1==q1&&c2==q2&&  s1==p2&&s2==p1&&s1==q2&&s2==q1&&c1==p2&&c2==q1&&c1==q2&&c2==q2){
                cout<<1;
            }else{
                cout<<0;
            }
        }
    //}
    return 0;
}
