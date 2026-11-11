#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
    }
    else{
        cout<<"0000";
        return 0;
    }
    int sum=0;
    for(int i=0;i<s1.size()-1;i++){
        if(s1[i]==s2[i]){
            sum++;
        }
    }
    if(sum==2){
        cout<<"1";
    }
    else{
        cout<<"000";
        return 0;
    }
    int l=0,r=0;
    if('A'<=s1[s1.size()-1]&&'C'>=s1[s1.size()-1]){
        l++;
    }
    else{
        r++;
    }
    if('A'<=s2[s2.size()-1]&&'C'>=s2[s2.size()-1]){
        l++;
    }
    else{
        r++;
    }
    if(l==2||r==2){
        cout<<"1";
    }
    else{
        cout<<"00";
        return 0;
    }
    if(s1[s1.size()-1]=='D'&&s2[s2.size()-1]=='F'){
        cout<<"1";
        return 0;
    }
    if(s1[s1.size()-1]-1==s2[s2.size()-1]||s1[s1.size()-1]+1==s2[s2.size()-1]){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    return 0;
}
