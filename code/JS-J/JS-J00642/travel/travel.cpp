#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using db=double;
using ldb=long double;

string c1,s1,c2,s2;
bool ans1,ans2,ans3,ans4;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    
    //Write Code HERE!!!!!!!!!
    
    cin>>c1>>s1>>c2>>s2;
    //Problem1
    if(c1==c2){
        ans1=1;
    }
    //Problem2
    if(ans1){
        if(s1[0]==s2[0] && s1[1]==s2[1]){
            ans2=1;
        }
    }
    //Problem3
    if(ans1 && ans2){
        if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C') && (s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
            ans3=1;
        }else if((s1[2]=='D'||s1[2]=='E') && (s2[2]=='D'||s2[2]=='E')){
            ans3=1;
        }
    }
    //Problem4
    if(ans1 && ans2 && ans3){
        char a=s1[2],b=s2[2];
        if(a=='A'&&b=='B'){
            ans4=1;
        }else if(a=='B'&&(b=='A'||b=='C')){
            ans4=1;
        }else if(a=='C'&&b=='B'){
            ans4=1;
        }else if(a=='D'&&b=='E'){
            ans4=1;
        }else if(a=='E'&&b=='D'){
            ans4=1;
        }
    }
    cout<<ans1<<ans2<<ans3<<ans4;
    return 0;
}
