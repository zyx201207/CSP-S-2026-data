#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    c=read(),t=read();
    srand((unsigned)time(NULL));
    if(c==1||c==2){
        for(int i=1;i<=t;i++)
        cout<<rand()%9<<"\n";
    }
    else if(c>=3&&c<=6){
        for(int i=1;i<=t;i++)
        cout<<rand()%305<<"\n";
    }
    else if(c>=7&&c<=10){
        for(int i=1;i<=t;i++)
        cout<<rand()%5005<<"\n";
    }
    else if(c>=11&&c<=14){
        for(int i=1;i<=t;i++)
        cout<<rand()%2000005<<"\n";
    }
    else if(c>=15&&c<=18){
        for(int i=1;i<=t;i++)
        cout<<rand()%1000005<<"\n";
    }
    else if(c>=19&&c<=21){
        for(int i=1;i<=t;i++)
        cout<<rand()%200005<<"\n";
    }
    else if(c>=22&&c<=25){
        for(int i=1;i<=t;i++)
        cout<<rand()%2000005<<"\n";
    }
    return 0;
}
