#include<bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;

string c1,s1,c2,s2;
bool flag,flag2;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<2;i++){
        if(c1[i]!=c2[i]){
            flag=true;
        }
    }
    cout<<(flag?"0":"1");
    for(int i=0;i<2;i++){
        if(s1[i]!=s2[i]){
            flag2=true;
        }
    }
    cout<<(flag2||flag?"0":"1");
    if(!flag2&&!flag){
        if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D'||s1[2]=='A'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='A'){
            cout<<"1";
        }
        else cout<<"0";
    }
    else cout<<"0";
    if(!flag2&&!flag){
        if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D'){
            cout<<"1";
        }
        else cout<<"0";
    }
    else cout<<"0";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
