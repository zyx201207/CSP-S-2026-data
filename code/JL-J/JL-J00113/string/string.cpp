#include<iostream>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,t=0,x;
    cin>>n;
    long long a[n],l=0,r=n-1;
    char c[n];
    for(long long i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }
    while(n>1){
        x=min(a[l],a[r]);
        if(c[l]!=c[r]) t+=x;
        a[l]-=x;
        a[r]-=x;
        if(a[l]==0){
            n--;
            l++;
        }
        if(a[r]==0){
            n--;
            r--;
        }
    }
    cout<<t;
    return 0;
}
/*
8:30 start
8:44 miao Q1;
9:58 gao ding Q2
10:00 Q3 pian fen
10:30 sha ye gan bu liao le......
11:00 ......
11:30 ......
12:00 jie shu le?
......
cai xue 2 yue de ju ruo jin li le......
zhe zhou hui qu hai you qi zhong kao shi......
wo zhen mei zhao le  qwq
zhi shao Q1 & Q2 neng na quan fen ......ying gai?
yi deng jiu bie zhi wang le ,
na ge er deng ying gai mei wen ti ba?
wu lun ru he
I love CCF
*/


