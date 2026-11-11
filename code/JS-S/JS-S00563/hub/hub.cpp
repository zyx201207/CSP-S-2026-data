#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
#define mp make_pair
#define pck putchar(' ')
#define pcn putchar('\n')
#define pb push_back
#define fir first
#define sec second
//#define int long long


using namespace std;

int read(){
    int k=1,x=0;
    char ch=gc();
    while(ch!='-' && !isdigit(ch)){
        ch=gc();
    }
    if(ch=='-'){
        k=-1;
        ch=gc();
    }
    while(isdigit(ch)){
        x=(x<<3)+(x<<1)+(ch^48);
        ch=gc();
    }
    return k*x;
}

void print(int x){
    if(x<0){
        pc('-');
        x=-x;
    }
    if(x<10){
        pc(x^48);
        return;
    }
    print(x/10);
    pc((x%10)^48);
}

void freop(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
}

vector<int> G[200200];
signed main(){
    freop();
    int testid=read(),T=read();
    while(T--){
        int n=read(),s=read();
        for(int i=1;i<=n;i++)G[i].clear();
        for(int i=1;i<n;i++){
            int u=read(),v=read();
            G[u].pb(v);
            G[v].pb(u);
        }
        if(testid==13 || testid==14){
            int m=(n+1)/2;
            if(s==1)print((m+1)/2);
            else if(s<=m-1)print((m-s+2)/4+1);
            else if(s<n)print(1);
            else print(0);
            pcn;
            continue;
        }
    }
    return 0;
}
/*
Time 14:30-18:30 don't forget!

luogu:AutumnQ(uid=1038710)
friend:moon_set

chennie,Cubber,absi2011,cmh,aaa_Pigeaon,offoff,Sving1024,placeholder,hyman00,UKB_wyx,TheSky233,LXGOD,rym,SNRJ,moon_set bless me!
The participant who sits next to me says that he is qqiq,is this true?
password:Oct31==Dec25?

No,I can't go to WC.
Maybe 100+100+32+10=242
Saaaaaaaaaaaaaaaaaaaad.
How to NOIP?
It's too difficult to try to join provincal team without stopping whk.

rp=inf;
*/