#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("travel5.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    vector<int>ans;
    if(c1==c2){
        ans.push_back(1);
    }else{
        ans.push_back(0);
        ans.push_back(0);
        ans.push_back(0);
        ans.push_back(0);
    }
    if(ans[0]==1){
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            ans.push_back(1);
        }else{
        ans.push_back(0);
        ans.push_back(0);
        ans.push_back(0);
        }
    }
    if(ans[1]==1){
        if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
            ans.push_back(1);
        }
        else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
            ans.push_back(1);
        }else{
            ans.push_back(0);
            ans.push_back(0);
    }
    }
    if(ans[2]==1){
        if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='F'&&s2[2]=='D')){
            ans.push_back(1);
        }else{
        ans.push_back(0);
        }
    }
    for(int i=0;i<4;i++){
        cout<<ans[i];
    }
    return 0;
}
