#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
//ll a[N];
map<ll,ll>mp;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);//check all int to long long
    cin.tie(0);
    cout.tie(0);
    ll n,m;

    cin>>n>>m;//cout<<n;
    ll lst=1e12+10;//min
    for(int i=1;i<=n;i++){
        //cin>>a[i];
        ll c;
        cin>>c;
        mp[c]++;
        lst=min(lst,c);
    }

    ll ohhh=0;
    ll maxn =-1e12-10,now=0;
    queue<ll> q;
//    q.push(lst);
    ll num=0;
    bool ddd=0;
//    bool fir=1;
//    //cout<<lst<<" "<<mp[lst]<<endl;
//    maxn=max(maxn,num);
    for(auto [a,b]:mp){
//        printf("a:%d b:%d num:%d lst:%d maxn:%d q.size():%d\n",a,b,num,lst,maxn,q.size());
//        if(fir){
//            fir=0;
//            continue;
//        }

        q.push(a);
        now+=(a-lst)*num;
        num+=b;
        lst=a;
        ll tnum,tnow;
        ddd=0;
        //printf("a:%d b:%d num:%d lst:%d maxn:%d q.size():%d now:%d\n",a,b,num,lst,maxn,q.size(),now);
        while(now>m&&q.size()){
            ddd=1;
            ll tmp=q.front();
            q.pop();
            now-=(a-tmp)*mp[tmp];
            num-=mp[tmp];
            ohhh=tmp;
//            cout<<"doing...\n";
        }
//        if(now>m&&!q.empty()){
//            ll tmp=q.front();
//            q.pop();
//            now-=(a-tmp)*mp[tmp];
//            num-=mp[tmp];
////            cout<<"deteting...\n";printf("a:%d b:%d num:%d lst:%d maxn:%d q.size():%d\n",a,b,num,lst,maxn,q.size());
//        }

//        while(tnow<m){
//            tnow+=a-ohhh;
//            tnum++;
//        }
       // tnum=(m-now)/ll(a-ohhh);
        //
        if(ddd){
            tnum=m-now;
            tnow=a-ohhh;
            //cout<<tnum<<" "<<tnow<<endl;
            if(tnow>0)tnum=tnum/tnow;
            else tnum=0;
        }else{
            tnum=0;
        }
        maxn=max(maxn,num+tnum);
        //printf("a:%d b:%d num:%d lst:%d maxn:%d q.size():%d now:%d\n",a,b,num,lst,maxn,q.size(),now);
    }

//    while(q.size()){
//        num-=mp[q.front()];
//        q.pop();
//    }
//    cout<<num<<endl;
    cout<<maxn;
    return 0;
}
