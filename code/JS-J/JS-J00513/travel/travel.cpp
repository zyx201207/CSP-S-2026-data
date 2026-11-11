#include<bits/stdc++.h>
using namespace std;
char c[110];
bool c1,c2,c3;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=1;i<=10;i++){
        cin>>c[i];
    }
    if(c[1]==c[6]&&c[2]==c[7]){
        c1=1;
        cout<<1;
    }else{
        cout<<0;
    }
    if(c1==1&&c[3]==c[8]&&c[4]==c[9]){
        c2=1;
        cout<<1;
    }else{
        cout<<0;
    }
    if(c2==1&&((c[5]=='A'||c[5]=='B'||c[5]=='C')&&(c[10]=='A'||c[10]=='B'||c[10]=='C'))||((c[5]=='D'||c[5]=='E')&&(c[10]=='D'||c[10]=='E'))){
        c3=1;
        cout<<1;
    }else{
        cout<<0;
    }
    if(c3==1&&abs(c[5]-c[10])==1){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
//02 01A 02 01B