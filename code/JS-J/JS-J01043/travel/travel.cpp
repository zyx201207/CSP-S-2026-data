#include<bits/stdc++.h>
using namespace std;
int x,y;
char a,b,c,d,e,f;
int ans1,ans2,ans3,ans4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>x>>a>>b>>c>>y>>d>>e>>f;
    if(x==y){
        ans1=1;
    }else ans1=0;
    if(ans1==1&&a==d&&b==e){
        ans2=1;
    }else ans2=0;
    if(ans1==1&&ans2==1&&((c=='A'&&f=='B')
                          ||(c=='A'&&f=='C')
                          ||(c=='B'&&f=='C')
                          ||(c=='D'&&f=='F')
                          ||(c=='B'&&f=='A')
                          ||(c=='C'&&f=='A')
                          ||(c=='C'&&f=='B')
                          ||(c=='F'&&f=='D'))){
        ans3=1;
    }else ans3=0;
    if(ans1==1&&ans2==1&&ans3==1&&((c=='A'&&f=='B')
                                   ||(c=='B'&&f=='C')
                                   ||(c=='D'&&f=='F')
                                   ||(c=='B'&&f=='A')
                                   ||(c=='C'&&f=='B')
                                   ||(c=='F'&&f=='D'))){
        ans4=1;
    }else ans4=0;
    printf("%d%d%d%d",ans1,ans2,ans3,ans4);
    return 0;
}
