#include<bits/stdc++.h>
using namespace std;
int n,m,flg=1;
int a[200050],ans[200050];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];ans[a[i]]++;
        if(a[i]<a[i-1])flg=0;
    }
    if(m==1){
        cout<<n;return 0;
    }
    if(m==2){
        int qq[]={0,0,0};
        qq[a[n]]=n;

        for(int i=n-1;i>=1;i--){
            qq[3-a[n]]+=(a[i]!=a[n]);
        }
        cout<<qq[1]<<' '<<qq[2];
        return 0;
    }
    if(flg){
        for(int i=1;i<=m;i++){
            ans[i]+=ans[i-1];cout<<ans[i]<<' ';
        }
        return 0;
    }
    for(int i=1;i<=m;i++){
        ans[i]+=ans[i-1];cout<<ans[i]<<' ';
    }
}

// wo qu zhong yu kai T4 le. 
// zhi sheng 70 min le, wo wu yi shi fen nu de
// dan shi zhe ge T4 kan qi lai hao nan a.
// wo gen ben xiang bu dao zuo fa yu shi wo 
// zhi neng ba ta dang zuo da mo ni xie le.
// suan le wo hai shi xie n<=2 de 20 pts bu 
// fen fen ba.
// wo qu, jing ran you 36 fen de bu fen fen
// rang wo xie. ZHE ME HAO. wo wu yi shi 
// xing fen de.
// wo gan jue xing zhi B ke yi zhuan hua wei
// n<=5000 de qing kuang dan shi wo bu hui zuo
// wo wu yi shi fen nu de. :(
// suo yi wo zhi neng lao shi xie bu fen fen
// qi si wo le hai bu neng ti qian zou
// suan le suan le jiao juan ba.
// bai bai.
