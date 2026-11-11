#include <bits/stdc++.h>

using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int ans=1;
    if(c1[0]=='0'&&c1[1]=='1'||c1[0]=='1'&&c1[1]=='6'||c2[0]=='0'&&c2[1]=='1'||c2[0]=='1'&&c2[1]=='6'){
        cout<<0<<0<<0<<0;
        return 0;
    }
    for(int i=0;i<c1.size();i++){
        if(c1[i]!=c2[i]){
            ans=0;
        }
    }
    if(ans==1){
        cout<<ans;
    }
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    ans=1;
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<ans;
    }
    else{
        cout<<0<<0<<0;
        return 0;
    }
    if((s1[2]>='A'&&s1[2]<'D'&&s2[2]=='D'||s2[2]=='E')||s2[2]>='A'&&s2[2]<'D'&&s1[2]=='D'||s1[2]=='E'){
        cout<<0<<0;
        return 0;
    }
    else{
        cout<<1;
    }
    if(s1[2]=='A'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='A'){
        cout<<0;
    }
    else{
        cout<<1;
    }
    return 0;
}
