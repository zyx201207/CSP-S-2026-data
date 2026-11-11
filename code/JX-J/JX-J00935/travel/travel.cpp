#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool check(char ch[],int n,char c){
    for(int i=0;i<n;++i) if(c==ch[i]) return true;
    return false;
}
int main()
  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else{
        cout<<"0000";
        return 0;
       }
    if(s1[0]==s2[0] && s1[1]==s2[1]) cout<<1;
    else{
        cout<<"000";
        return 0;
       }
    char ch1[]={'A','B','C'},ch2[]={'D','F'};
    if((check(ch1,3,s1.back()) && check(ch1,3,s2.back())) || check(ch2,2,s1.back()) && check(ch2,2,s2.back())) cout<<1;
    else{
        cout<<"00";
        return 0;
       }
    if(abs(s1.back()-s2.back())==1) cout<<1;
    else cout<<0;
    return 0;
  }
