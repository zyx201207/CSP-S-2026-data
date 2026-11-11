#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a!=c){
        cout<<0;
    }
    else{
        cout<<1;
    }
    int flag=0;
    for(int i=0;i<2;i++){
        if(b[i]!=d[i]){
            cout<<"000";
            flag=1;
            return 0;
        }
    }
    if(flag==0){
        cout<<1;
    }
    if((b[2]-'C'<=0&&d[2]-'C'<=0)||(b[2]-'C'>0&&d[2]-'C'>0)){
            cout<<1;
        if((b[2]-'1'==d[2]-'0')||(b[2]-'0'==d[2]-'1')){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    else{
        cout<<"00";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
