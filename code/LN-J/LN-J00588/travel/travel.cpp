#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    int dib=10*(int(b[0])-48)+int(b[1])-48;
    int did=10*(int(d[0])-48)+int(d[1])-48;
    if(a!=c)cout<<"0000";
    else if(dib!=did)cout<<"1000";
    else if(b[2]=='D' && d[2]=='F' || b[2]=='F' && d[2]=='D'){
        cout<<"1111";
    }
    else if(b[2]<=67 && d[2]>67 || b[2]>67 && d[2]<=67){
        cout<<"1100";
    }
    else{
         if(abs(b[2]-d[2])==1){
              cout<<"1111";
         }
         else cout<<"1110";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
