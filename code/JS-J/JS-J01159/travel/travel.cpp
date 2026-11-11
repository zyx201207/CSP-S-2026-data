#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>a>>b>>c>>d;
    if(a!=c){
        cout<<"0000";
        return 0;
    }else{
        if(b[0]!=d[0]||b[1]!=d[1]){
            cout<<"1000";
            return 0;
        }else{
            if(b[2]>='A'&&b[2]<='C'&&d[2]>='D'&&d[2]<='F'||b[2]>='D'&&b[2]<='F'&&d[2]>='A'&&d[2]<='C'){
                cout<<"1100";
                return 0;
            }else{
                int t1=b[2]-'A';
                int t2=d[2]-'A';
                if(t1==3&&t2==5||t1==5&&t2==3||abs(t1-t2)==1){
                    cout<<"1111";
                    return 0;
                }
                else{
                    cout<<"1110";
                    return 0;
                }
            }
        }
    }
    return 0;
}
