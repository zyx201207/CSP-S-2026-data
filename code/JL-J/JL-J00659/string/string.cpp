#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    string s,s1;
    cin>>s>>s1;
    int h=0;
    int x=s.size();
    for(int i=0;i<x/2;i++){
        if(s[i]!=s[x-i])h++;
        if(s1[i]!=s1[x-i])h++;
    }
    cout<<h;
    return 0;
}
