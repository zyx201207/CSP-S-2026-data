#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    string ans="";
    if(c1==c2) ans=ans+'1';
    else{
        cout<<"0000";
        return 0;
    }
    string t1=s1.substr(0,2),t2=s2.substr(0,2);
    if(t1==t2) ans=ans+'1';
    else ans=ans+'0';
    int flag=0;
    if((s1[s1.size()-1]<='C'&&s2[s2.size()-1]<='C')||(s1[s1.size()-1]>='D'&&s2[s2.size()-1]>='D')){
        if(t1==t2) ans=ans+'1',flag=1;
        else ans=ans+'0';
    }
    else ans=ans+'0';
    if(flag==1){
        int c=abs(s1[s1.size()-1]-s2[s2.size()-1]);
        if(s1[s1.size()-1]>='D') ans=ans+'1';
        else if(c==1) ans=ans+'1';
        else ans=ans+'0';
    }
    else ans=ans+'0';
    cout<<ans;
    return 0;
}
