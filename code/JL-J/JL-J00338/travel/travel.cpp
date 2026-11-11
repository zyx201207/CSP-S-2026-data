#include<bits/stdc++.h>
using namespace std;
struct P{
    int x,pai,hao;
};
P a,b;
void init(P &x,string s,string t){
    x.x=stoi(s);
    if(t[2]=='F')x.hao=5;
    else x.hao=t[2]-'A'+1;
    int y=0;
    for(int i=0;i<2;i++) y=y*10+t[i]-'0';
    x.pai=y;
}
bool ans[10];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s,t;
    cin>>s>>t;
    init(a,s,t);
    cin>>s>>t;
    init(b,s,t);
    if(a.x==b.x){
        ans[0]=1;
        if(a.pai==b.pai){
            ans[1]=1;
            if((a.hao>3)==(b.hao>3)){
                ans[2]=1;
                if(abs(a.hao-b.hao)==1){
                    ans[3]=1;
                }
            }
        }
    }
    for(int i=0;i<4;i++)cout<<ans[i];
    return 0;
}
