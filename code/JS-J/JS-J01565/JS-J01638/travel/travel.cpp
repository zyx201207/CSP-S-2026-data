#include<bits/stdc++.h>
#define int long long
using namespace std;

string x,y;
bool p[4];
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
    }else{
        p[0]=1;
    }
    for(int i=0;i<2;i++){
        x=x+a2[i];
        y=y+b2[i];
    }
    if(x==y){
        p[1]=1;
    }else{
        cout<<"1000";
        return 0;
    }
    x=a2[2],y=b2[2];
    if((x=="F"&&y=="D")||(y=="F"&&x=="D")){
        cout<<"1111";
        return 0;
    }else if((x=="A"||x=="B"||x=="C")&&(y=="A"||y=="B"||y=="C")){
        if((x=="A"&&y=="B")||(x=="B"&&y=="A")||(x=="B"&&y=="C")||(x=="C"&&y=="B")){
            cout<<"1111";
        }else{
            cout<<"1110";
        }
        return 0;
    }
    cout<<"1100";
    return 0;
}