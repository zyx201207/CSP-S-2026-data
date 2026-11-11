#include <iostream>
using namespace std;
string s1,s2;
int a,b,ans1,ans2,ans3,ans4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>s1>>b>>s2;
    if (a!=b){
        ans1=0,ans2=0,ans3=0,ans4=0;
    }
    else{
        ans1=1;
        int x=(s1[0]-'0')*10+(s1[1]-'0'),y=(s2[0]-'0')*10+(s2[1]-'0');
        if (x!=y){
            ans2=0,ans3=0,ans4=0;
        }
        else{
            ans2=1;
            if (s1[2]=='A'&&s2[2]=='D'||s1[2]=='A'&&s2[2]=='F'||s1[2]=='B'&&s2[2]=='D'||s1[2]=='B'&&s2[2]=='F'||s1[2]=='C'&&s2[2]=='D'||s1[2]=='C'&&s2[2]=='F'||s1[2]=='D'&&s2[2]=='A'||s1[2]=='F'&&s2[2]=='A'||s1[2]=='D'&&s2[2]=='B'||s1[2]=='F'&&s2[2]=='B'||s1[2]=='D'&&s2[2]=='C'||s1[2]=='F'&&s2[2]=='C'){
                ans3=0,ans4=0;
            }
            else{
                ans3=1;
                if (s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D'||s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='C'&&s2[2]=='B'){
                    ans4=1;
                }
                else ans4=0;
            }
        }
    }
    cout<<ans1<<ans2<<ans3<<ans4;
    return 0;
}
