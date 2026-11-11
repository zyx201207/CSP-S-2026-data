#include <bits/stdc++.h>
using namespace std;
using ll=long long;


struct ss{
    ll a;
    char c;
};

ss s[200005];

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> s[i].a >> s[i].c;
    }
    /*
    ll si=1, sj=1, ei=n, ej=s[n].a;
    ll cnt=0;
    while(si!=ei || (sj!=ej&&sj-ej!=-1)){
        if(s[si].c!=s[ei].c){
            cnt++;
        }
        sj++;
        ej--;
        if(sj>s[si].a){
            sj=0;
            si++;
        }
        if(ej<1){
            ei--;
            ej=s[ei].a;
        }
    }
    cout << cnt;
    */
    ll cnt=0;
    ll st=1,en=n;
    while(!((st==en && n%2!=0)||(abs(st-en)==1&&n%2==0))){
        ll mn=min(s[st].a, s[en].a);
        if(s[st].c==s[en].c){

        }else{
            cnt+=mn;
        }
        s[st].a-=mn;
        s[en].a-=mn;
        if(!s[st].a) st++;
        if(!s[en].a) en--;
    }
    if(n%2==0){
        ll mn=min(s[st].a, s[en].a);
        if(s[st].c==s[en].c){

        }else{
            cnt+=mn;
        }
    }
    cout << cnt;
    return 0;
}
