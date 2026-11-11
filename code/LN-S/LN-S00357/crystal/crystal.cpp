#include <bits/stdc++.h>
using namespace std;

vector<long long> crystals,pre;

inline long long ask(long long from,long long to){
    return pre[to]-pre[from]+crystals[from];//sigma(from,to)
}

inline bool check(long long from,long long to,long long m){
    return (ask(from,to)+m)>=(to-from+1)*crystals[to];
}//sigma(from,to)+m>=(to-from)*crystals[to]

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    long long m,n;
    cin>>n>>m;
//
    crystals.resize(n);
    for(int i=0;i<n;i++){//readin
        cin>>crystals[i];
    }sort(crystals.begin(),crystals.end());
//
    pre=crystals;
    for(int i=1;i<n;i++){//pre sum
        pre[i]=pre[i-1]+pre[i];
        
    }
//
    vector<long long> ans(n,0);
    
    for(long long to=1;to<n;to++){
        long long fromL=0,fromR=to;
        long long ansfrom=-1;
        while(fromL<fromR){
            long long fromMid=(fromL+fromR)/2;


            if(check(fromMid,to,m)){//T
                fromR=fromMid;
                ansfrom=fromMid;
            }else{//F
                fromL=fromMid+1;
            }
        }
        ans[to]=to-ansfrom+1;//？？？？
    }

    long long output=-0x3f3f3f3f;
    for(auto now:ans){
        output=max(now,output);
    }

    cout<<output;

    









    return 0;
}