#include<iostream>
#define N 200005
using namespace std;
struct str{
    char a;
    long long b,e,num;
}s[N],fs[N];
int n;
long long c,ans,p,lp;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].num;
        c+=s[i].num;
        s[i].e=c;
        s[i].b=c-s[i].num+1;
    }
    ans=c;
    for(int i=1;i<=n;i++){
        fs[i].a=s[n-i+1].a;
        fs[i].num=s[n-i+1].num;
        fs[i].b=c-s[i].e+1;
        fs[i].e=c-s[i].b+1;
    }
    int ln=1,rn=1;
    p=min(s[ln].e,fs[rn].e);
    while(p<=ans){
        if(s[ln].a==fs[rn].a){
            ans-=p-lp+1;
        }
        if(s[ln].e<fs[rn].e){
            ln++;
            lp=p;
            p=min(s[ln].e,fs[rn].e);
        }else if(s[ln].e>fs[rn].e){
            rn++;
            lp=p;
            p=min(s[ln].e,fs[rn].e);
        }else{
            ln++;
            rn++;
            lp=p;
            p=min(s[ln].e,fs[rn].e);
        }
    }
    cout<<ans<<endl;
}
