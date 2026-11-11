#include<bits/stdc++.h>
using namespace std;
struct abcd{
    long long d,cnt=0;
}st[500005];
long long n,m,a[500005],pos,tsh,maxx=-1;
long long func(int x){
    int res=st[x].cnt;
    int y=m;
    for(int i=x-1;i>=1;i--){
        if(st[i].cnt*(st[x].d-st[i].d)<=y){
            y-=st[i].cnt*(st[x].d-st[i].d);
            res+=st[i].cnt;
        }
        else return res+y/(st[x].d-st[i].d);
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    a[0]=2000000000;
    for(int i=1;i<=n;i++){
        if(a[i]!=a[i-1]) st[++pos].d=a[i];
        st[pos].cnt++;
    }
    for(int i=1;i<=pos;i++){

        maxx=max(maxx,func(i));
    }
    cout<<maxx;
    return 0;
}
