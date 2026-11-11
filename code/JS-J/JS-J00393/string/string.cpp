#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n;
ll a[N];
char c[N];
struct node{
    int num;
    ll pos;
    ll dis;
};
ll st[N],ed[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>c[i];
    ll L=0;
    //init
    for(int i=1;i<=n;i++) L+=a[i];
    st[1]=0;
    for(int i=2;i<=n;i++)
        st[i]=st[i-1]+a[i-1];
    for(int i=1;i<n;i++)
        ed[i]=st[i+1]-1;
    ed[n]=L-1;
    //calc
    node i={1,0LL,1LL*a[1]},j={n,L-1,1LL*a[n]};
    ll ans=0;
    while(i.num<j.num){
        //cout<<i.num<<" "<<j.num<<'\n';
        if(i.dis==j.dis){
            if(c[i.num]!=c[j.num])
                ans+=i.dis;
            i.num++;
            i.pos=st[i.num];
            i.dis=a[i.num];
            j.num--;
            j.pos=ed[j.num];
            j.dis=a[j.num];
        }
        else if(i.dis<j.dis){
            if(c[i.num]!=c[j.num])
                ans+=i.dis;
            j.pos-=i.dis;
            j.dis-=i.dis;
            i.num++;
            i.pos=st[i.num];
            i.dis=a[i.num];
        }
        else{
            if(c[i.num]!=c[j.num])
                ans+=j.dis;
            i.pos+=j.dis;
            i.dis-=j.dis;
            j.num--;
            j.pos=ed[j.num];
            j.dis=a[j.num];
        }
    }
    cout<<ans<<'\n';
    return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
