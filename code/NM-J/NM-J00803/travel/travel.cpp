#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio;
    cin.tie(0);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;

    }else{
        cout<<0000;
        return 0;
    }
    int sum1=s1[0]*10+s1[1];
    int sum2=s2[0]*10+s2[1];
    if(sum1==sum2){
        cout<<1;
    }else{
        cout<<000;
        return 0;
    }
    cout<<00;
    fclose(stdin);
    fclose(stdout);
    return 0;
}