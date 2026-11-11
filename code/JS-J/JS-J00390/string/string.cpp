#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct Node{
    long long cnt;
    char ch;
};
Node a[N];
int mini(Node a,Node b){
    if(a.cnt<b.cnt)return a.cnt;
    else return b.cnt;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].cnt;
        cin>>a[i].ch;
    }
    long long i=1,j=n;
    long long ans=0;
    while(i<j){
        int tmp=mini(a[i],a[j]);
        if(a[i].ch==a[j].ch){
            a[i].cnt-=tmp;
            a[j].cnt-=tmp;
        }else{
            ans+=tmp;
            a[i].cnt-=tmp;
            a[j].cnt-=tmp;
        }
        if(a[i].cnt<=0)i++;
        if(a[j].cnt<=0)j--;
    }
    cout<<ans<<'\n';
    return 0;
}
