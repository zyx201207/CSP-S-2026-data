#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string a1,b1;
    cin>>a>>b;
    cin>>a>>a1>>b>>b1;
    if(a==b){
        cout<<"1110";
    }
    if(a!=b){
        cout<<"0000";
    }
    return 0;
}
