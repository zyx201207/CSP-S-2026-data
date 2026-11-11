#include<bits/stdc++.h>
using namespace std;
const int MAX=10086;
int a[MAX];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int pai1=int(s1[0]*10+s1[1]);
    int pai2=int(s2[0]*10+s2[1]);
    int ce1=int(s1[2]);
    int ce2=int(s2[2]);
    if(c1==c2){
        if(pai1==pai2){
            if(ce1<=67 and ce1>=65 and ce2<=67 and ce2>=65){
                    if(ce1==65 and ce2==67 or ce1==67 and ce2==65){
                        cout<<"1110";
                    }else{
                        cout<<"1111";
                    }
            }else if(ce1==int('D') and ce2==int('F') or ce2==int('D') and ce1==int('F')){
                    cout<<"1111";
            }else{
                cout<<"1100";
            }
        }else{
            cout<<"1000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
