#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0,f=1;
    char c=getchar_unlocked();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+(c-'0');
        c=getchar_unlocked();
    }
    return x*f;
}
string s1,s2;
int length;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n=read();
    for(int i=1;i<=n;i++){
        int a=read();
        string c;
        cin>>c;
        if(a<=500){
            length+=a;
            for(int i=1;i<=a;i++){
                s1.append(c);
                s2.append(c);
            }
        }
    }
    reverse(s1.begin(),s1.end());
    int c=0;
    for(int i=0;i<length;i++){
        if(s1[i]!=s2[i]) c++;
    }
    printf("%d",c/2);
    return 0;
}
//11:40
//76pts
//maybe just 100+76+25+0
//201,how to 1=
//rp++ pls
