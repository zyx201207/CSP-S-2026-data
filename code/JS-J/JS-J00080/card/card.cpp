#include<bits/stdc++.h>
using namespace std;
struct cardd{
    int number;
    int seat;
    int ans;
};
int solve(cardd cards[],int now,int n){
    for(int i=now-1;i<n;++i){
        if(cards[cards[i].number].seat==0)
            cards[cards[i].number].seat=i;
        else{
            for(int m= cards[cards[i].number].seat;m<i;++m)
                 cards[m].seat=0;
            cards[cards[i].number].seat=0;
        }
    }
    if(cards[now].seat!=0)
        cards[now].ans++;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    char a[n];
    string leaved;
    cardd cards[300005];
    for(int i=0;i<n;++i){
        cin>>cards[i].number;
    }
    for(int i=0;i<m;++i){
        solve(cards,i,n);
    }
    for(int i=0;i<m;++i)
        cout<<cards[i].ans<<' ';
}
