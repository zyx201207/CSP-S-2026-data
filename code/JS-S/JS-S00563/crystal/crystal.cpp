#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
#define mp make_pair
#define pck putchar(' ')
#define pcn putchar('\n')
#define pb push_back
#define fir first
#define sec second
#define int long long


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
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
}

int a[500500];
int S[505055];
signed main(){
    freop();
    int n=read(),m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)S[i]=S[i-1]+a[i];
    int ans=1;
    for(int i=1;i<=n;i++){
        int L=1,R=i-1;
        int now=0;
        while(L<=R){
            int mid=(L+R)>>1;
            int Sum=S[i-1]-S[i-mid-1];
            int need_op=a[i]*mid-Sum;
            if(need_op<=m)now=mid,L=mid+1;
            else R=mid-1;
        }
        ans=max(ans,now+1);
    }
    print(ans);pcn;
    return 0;
}
/*
Time 14:30-18:30 don't forget!

luogu:AutumnQ(uid=1038710)
friend:moon_set

chennie,Cubber,absi2011,cmh,aaa_Pigeaon,offoff,Sving1024,placeholder,hyman00,UKB_wyx,TheSky233,LXGOD,rym,SNRJ,moon_set bless me!
The participant who sits next to me says that he is qqiq,is this true?

rp=inf;

Maybe 14:28 I think out T1's idea?
Maybe 14:43 AC Sample 4/4
*/