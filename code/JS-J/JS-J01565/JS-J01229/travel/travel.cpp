#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s1,s2;
char c1,c2,c3,c4,c5,c6;
int f1,f2;
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("travel.in",'r',stdin);
    freopen("travel.out",'w',stdout);
    cin>>s1>>c1>>c2>>c3>>s2>>c4>>c5>>c6;
    if(s1 == s2){
        cout<<1;
        if(c1 == c4 && c2 == c5){
            cout<<1;
            if(c3 == 'A' || c3 == 'B' || c3 == 'C') f1 = 1;
            else f1 = 2;
            if(c6 == 'A' || c6 == 'B' || c6 == 'C') f2 = 1;
            else f2 = 2;
            if(f1 == f2){
                cout<<1;
                if(f1 == 2 && f2 == 2){
                    cout<<1;
                    return 0;
                }else{
                    if((c3 == 'A' && c6 == 'B') || (c3 == 'B' && c6 == 'C') || (c3 == 'B' && c6 == 'A') || (c3 == 'C' && c6 == 'B')){
                        cout<<1;
                        return 0;
                    }else{
                        cout<<0;
                        return 0;
                    }
                }
            }else{
                cout<<"00";
                return 0;
            }

        }else{
            cout<<"000";
            return 0;
        }
    }else{
        cout<<"0000";
        return 0;
    }
    return 0;
}
