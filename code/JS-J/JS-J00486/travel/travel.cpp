#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4,ans;
int p=0,pp=0;
int main(){
    freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    for(int i=1;i<=3;i++){
        if(i<3){
            if(s1[i]==s3[i]){
                p=1;
                ans[1]='1';
                if(s2[i]=s4[i]){
                    pp=2;
                    ans[2]='1';
                }
                else {
                    for(int j=2;j<=4;j++)ans[j]='0';
                    break;
                }
            }
            else {
                for(int j=1;j<=4;j++)ans[j]='0';
                break;
            }
        }
        if(i==3&&p==1&&pp==2){
            if(s2[i]=='A'&&s4[i]=='B')ans[3]='1';ans[4]='1';
            else if(s2[i]=='A'&&s4[i]=='C')ans[3]='1';ans[4]='0';
            else if(s2[i]=='B'&&s4[i]=='A')ans[3]='1';ans[4]='1';
            else if(s2[i]=='B'&&s4[i]=='C')ans[3]='1';ans[4]='1';
            else if(s2[i]=='C'&&s4[i]=='A')ans[3]='1';ans[4]='0';
            else if(s2[i]=='C'&&s4[i]=='B')ans[3]='1';ans[4]='1';
            else if(s2[i]=='E'&&s4[i]=='F')ans[3]='1';ans[4]='1';
            else if(s2[i]=='F'&&s4[i]=='E')ans[3]='1';ans[4]='1';
            else ans[3]='0';ans[4]='0';
        }
    }for(int j=1;j<=4;j++)cout<<ans[j];
    return 0;
}
