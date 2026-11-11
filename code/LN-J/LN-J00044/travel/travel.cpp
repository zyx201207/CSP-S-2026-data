#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string n,m,w,s;
    cin>>n>>m>>w>>s;
    if(n==w){
        cout<<"1"<<" ";
        if(m[0]==s[0]&&m[1]==s[1]){
            cout<<"1"<<" "<<"1"<<" "<<"1";
        }else{
            cout<<"0"<<" "<<"0"<<" "<<"0";
            return 0;
        }
    }else{
        cout<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0";
        return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
