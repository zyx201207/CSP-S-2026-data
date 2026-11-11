#include<bits/stdc++.h>
using namespace std;
int cnt;
string c1,c2,s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cnt++;
        if(s1[0]==s2[0] && s1[1]==s2[1]){
            cnt++;
            if((s1[2]<='C' && s2[2]<='C') || (s1[2]>='D' && s2[2]>='D')){
                cnt++;
                if(abs((int)s1[2]-(int)s2[2])==1 || (s1[2]=='D' && s2[2]=='F') || (s1[2]=='F' && s2[2]=='D'))
                    cnt++;
            }
        }
    }
    for(int i=1;i<=cnt;i++)
        cout<<1;
    for(int i=cnt+1;i<=4;i++)
        cout<<0;
    cout<<"\n";
    return 0;
}
