#include<bits/stdc++.h>
#define ai first
#define ci second
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    pair<int,char>xh,xt;
    deque<pair<int,char>>a;
    for(int i=1;i<=n;i++){
        cin>>xh.ai>>xh.ci;
        a.push_back(xh);
    }
    long long ans=0;
    pair<int,char>tph{0,0},tpt(0,0);
    while(!(a.empty())){
        if(tph.ai>0){
            xt=a.back();
            a.pop_back();
            xt.ai-=tph.ai;
            if(xt.ai<=0){
                if(tph.ci!=xt.ci)
                    ans+=xt.ai+tph.ai;
                tph.ai=-xt.ai;
                continue;
            }
            if(tph.ci!=xt.ci){
                ans+=tph.ai;
            }
            tph.ai=0;
            if(a.empty())break;
            xh=a.front();
            a.pop_front();
            xh.ai-=xt.ai;
            if(xh.ai<=0){
                if(xh.ci!=xt.ci)
                    ans+=xh.ai+xt.ai;
                tpt={-xh.ai,xt.ci};
                continue;
            }
            if(xh.ci!=xt.ci)
                ans+=xt.ai;
            tph=xh;
        }else{
            xh=a.front();
            a.pop_front();
            xh.ai-=tpt.ai;
            if(xh.ai<=0){
                if(tpt.ci!=xh.ci)
                    ans+=xh.ai+tpt.ai;
                tpt.ai=-xh.ai;
                continue;
            }
            if(tpt.ci!=xh.ci){
                ans+=tpt.ai;
            }
            tpt.ai=0;
            if(a.empty())break;
            xt=a.back();
            a.pop_back();
            xt.ai-=xh.ai;
            if(xt.ai<=0){
                if(xh.ci!=xt.ci)
                    ans+=xt.ai+xh.ai;
                tph={-xt.ai,xh.ci};
                continue;
            }
            if(xh.ci!=xt.ci)
                ans+=xh.ai;
            tpt=xt;
        }
    }
    cout<<ans;
    return 0;
}