#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    int a[4];
    memset(a,0,sizeof(a));
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        a[0]=1;
        if(s1[0]+s1[1]==s2[0]+s2[1]){
            a[1]=1;
            if('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C'){
                a[2]=1;
                int x=s1[2]-'A',y=s2[2]-'A';
                if(abs(x-y)==1) a[3]=1;
            }
            else if('D'<=s1[2]&&s1[2]<='F'&&'D'<=s2[2]&&s2[2]<='F'){
                a[2]=1;
                a[3]=1;
            }
        }
    }
    for(int i=0;i<4;i++) cout<<a[i];
    return 0;
}
