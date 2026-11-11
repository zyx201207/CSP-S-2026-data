#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int n,m;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>s1>>m>>s2;
    cout<<(n==m ? 1 : 0);
    if((n==m ? 1 : 0)==0){
        cout<<"000";
        return 0;
    }
    cout<<((n==m&&s1[0]==s2[0]&&s1[1]==s2[1]) ? 1 : 0);
    if(((n==m&&s1[0]==s2[0]&&s1[1]==s2[1]) ? 1 : 0)==0){
        cout<<"00";
        return 0;
    }
    if((n==m&&s1[0]==s2[0]&&s1[1]==s2[1])&&(s1[2]=='A'&&(s2[2]=='B'||s2[2]=='C'))||(s1[2]=='B'&&(s2[2]=='C'||s2[2]=='A'))||(s1[2]=='C'&&(s2[2]=='A'||s2[2]=='B'))||(s1[2]=='D'&&s2[2]=='E')||(s1[2]=='E'&&s2[2])){
        cout<<1;
        if(abs(s1[2]-s2[2])==1){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }else{
        cout<<0;
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
