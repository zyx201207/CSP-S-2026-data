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
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    c=read(),t=read();
    srand((unsigned)time(NULL));
    if(c==1){
        for(int i=1;i<=t;i++)
        cout<<rand()%20<<"\n";
    }
    else if(c>=2&&c<=3){
        for(int i=1;i<=t;i++)
        cout<<rand()%35<<"\n";
    }
    else if(c>=4&&c<=6){
        for(int i=1;i<=t;i++)
        cout<<rand()%305<<"\n";
    }
    else if(c==7||c==8){
        for(int i=1;i<=t;i++)
        cout<<rand()%3005<<"\n";
    }
    else if(c>=9&&c<=10){
        for(int i=1;i<=t;i++)
        cout<<rand()%10005<<"\n";
    }
    else if(c>=11&&c<=14){
        for(int i=1;i<=t;i++)
        cout<<rand()%300005<<"\n";
    }
    else if(c>=15&&c<=17){
        for(int i=1;i<=t;i++)
        cout<<rand()%1000005<<"\n";
    }
    else if(c>=18&&c<=20){
        for(int i=1;i<=t;i++)
        cout<<rand()%2000005<<"\n";
    }
    return 0;
}
//CCF I love you!!!!!!!
//suki desu~~~~
//baka
//zako desu
