#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string x,y;
    cin>>a>>x>>b>>y;
    if(a!=b){
        cout<<"0000";
        return 0;
    }else{
        if(x[1]!=y[1]){
            cout<<"1000";
            return 0;
        }else{
            if(x[2]-'A'<3&&y[2]-'A'<3){
                if(x[2]=='B'||y[2]=='B'){
                    cout<<"1111";
                    return 0;
                }else{
                    cout<<"1110";
                    return 0;
                }
            }
            if(x[2]-'D'<=2&&y[2]-'D'<=2&&y[2]-'D'>=0&&x[2]-'D'>=0){
                    cout<<"1111";
                    return 0;
            }else{
                cout<<"1100";
                return 0;
            }
        }
    }
    return 0;
}
