#include<bits/stdc++.h>
using namespace std;
struct r{
      string chexiang;
      string seat;
}a,b;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a.chexiang>>a.seat>>b.chexiang>>b.seat;
    int shu[4]={0};
    if(a.chexiang==b.chexiang) shu[0]=1;
    else {
        shu[0]=0;
    }

    if(a.seat[0]==b.seat[0]&&a.seat[1]==b.seat[1]) shu[1]=1;
    else{
        shu[1]=0;
    }

    int word1=int(a.seat[2]);
    int word2=int(b.seat[2]);
    if(word1<=67&&word2<=67) shu[2]=1;
    else if(word1<=70&&word1>67&&word2>67&&word2<=70) shu[2]=1;
    else shu[2]=0;

    if(shu[2]==1&&abs(word1-word2)==1) shu[3]=1;
    else shu[3]=0;
    for(int i=0;i<4;i++){
        cout<<shu[i];
    }
    return 0;
}
