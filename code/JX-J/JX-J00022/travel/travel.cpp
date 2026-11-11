#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("math.in","r",stdin);
    freopen("math.out","w",stdout);
    char c1,c2;
    int a,b,c,d;
    cin>>a>>b>>c1>>c>>d>>c2;
    if(a==c){
        if(b==d||d==b){
            if(c1=='A'&&c2=='B'||c1=='B'&&c2=='A'||c1=='B'&&c2=='C'||c1=='C'&&c2=='B'||c1=='D'&&c2=='E'||c1=='E'&&c2=='D'){
                cout<<"1111";
            }
            else{
                cout<<"1100";
            }
        }
        else{
            cout<<"1000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
