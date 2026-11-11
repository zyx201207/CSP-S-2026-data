#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
string s1,s2;
char a1,a2;
bool flag=0,flag1=0,flag2=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2>>c3>>c4;
    if(c1==c3){
        flag1=1;
        cout<<1;
    }
    else cout<<0;
    for(int i=0;i<c2.size();i++){
        if(c2[i]>='0'&&c2[i]<='9') s1+=c2[i];
        if(c2[i]>='A'&&c2[i]<='Z') a1=c2[i];
    }
    for(int i=0;i<c4.size();i++){
        if(c4[i]>='0'&&c4[i]<='9') s2+=c4[i];
        if(c4[i]>='A'&&c4[i]<='Z') a2=c4[i];
    }
    if(s1==s2&&flag1){
        cout<<1;
        flag=1;
    }
    else cout<<0;
    if(flag&&((a1>='A'&&a1<='C')&&(a2>='A'&&a2<='C'))||((a1>='D'&&a1<='F')&&(a2>='D'&&a2<='F'))){
        flag2=1;
        cout<<1;
    }
    else cout<<0;
    int aa=a1-'A';
    int bb=a2-'A';
    if(flag2&&(aa-1==bb||aa+1==bb)) cout<<1;
    else cout<<0;
    return 0;
}
