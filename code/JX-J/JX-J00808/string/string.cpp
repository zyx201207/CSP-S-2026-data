#include<bits/stdc++.h>
using namespace std;
constexpr int MAXN=2e5+1,INF=0x3f3f3f3f;
using ll=long long;
class dd{
    public:
        int a;
        char c;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    dd s[MAXN]={};
    bool d[MAXN]={};
    ll lt=0,rt=0,len=0,ans=0;
    int li=1,ri=0,n;
    cin>>n;
    ri=n;
    for (int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].c;
        len+=s[i].a;
    }
    dd l={0,0},r={0,0};
    while(lt<=len/2||rt<=len/2){
        if(l.a==0){
            if(d[li]==0){
                l=s[li];
                lt+=s[li].a;
                d[li]=1;
                li++;
            }
        }
        if(r.a==0){
            if(d[ri]==0){
                r=s[ri];
                rt+=s[ri].a;
                d[ri]=1;
                ri--;
            }
        }
        if(l.a==0||r.a==0)break;
        //printf("Now: R:%d,%c;L:%d,%c;lt:%d,rt:%d;li:%d,ri:%d;len:%d\n",l.a,l.c,r.a,r.c,lt,rt,li,ri,len);
        if(r.a>=l.a){
            if(r.c!=l.c){
                ans+=l.a;
            }
            dd tmp=r;
            r={0,0};
            tmp.a-=l.a;
            r=tmp;
            l={0,0};
        }
        else if(r.a<l.a){
            if(r.c!=l.c){
                ans+=r.a;
            }
            dd tmp=l;
            l={0,0};
            tmp.a-=r.a;
            l=tmp;
            r={0,0};
        }
    }
    cout<<ans;
}
