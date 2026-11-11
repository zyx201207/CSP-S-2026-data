#include<bits/stdc++.h>
using namespace std;
//#define int long long
int n,a[200010],pos,kuai,duoy,dang;
long long tot;
int ans;
char c[200010],midc;
stack<pair<int,char>>s1,s2;
bool ck(){//
    long long tott=0ll;
    for(int i=1;i<=n;i++){
        tott+=1ll*a[i];
        if(tott*2ll==tot){
            return true;
        }
        if(tott*2ll>tot){
            return false;
        }
    }
}
void sol(){
    long long tott=0ll;
    for(int i=1;i<n;i++){
        tott+=1ll*a[i];
        if(tott*2<tot&&(tott+a[i+1])*2>tot){
            kuai=i;
            if(tot%2==1ll){
                duoy=tot/2+1-tott;
            }
            else{
                duoy=tot/2-tott;
            }
            dang=a[i+1];
            midc=c[i+1];
            return;
        }
    }
    return;
}
int ttt(){
    long long tott=0ll;
    for(int i=1;i<=n;i++){
        tott+=1ll*a[i];
        if(tott*2==tot){
            return i;
        }
    }
}
void work(){
    while(!s1.empty()&&!s2.empty()){
        pair<int,char>t1,t2;
        t1=s1.top();
        t2=s2.top();
        if(t1.second==t2.second){
            if(!s1.empty()&&!s2.empty()){
                s1.pop();
                s2.pop();
                int temp=min(t1.first,t2.first);
                t1.first-=temp;
                t2.first-=temp;
                if(t1.first!=0){
                    s1.push(t1);
                }
                if(t2.first!=0){
                    s2.push(t2);
                }
            }
        }
        else{
            if(!s1.empty()&&!s2.empty()){
                s1.pop();
                s2.pop();
                int temp=min(t1.first,t2.first);
                ans+=temp;
                t1.first-=temp;
                t2.first-=temp;
                if(t1.first!=0){
                    s1.push(t1);
                }
                if(t2.first!=0){
                    s2.push(t2);
                }
            }
        }
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        tot+=a[i];
    }
    bool flag=ck();
    if(flag==1){
        int ttttt=ttt();
        while(!s1.empty()){
            s1.pop();
        }
        while(!s2.empty()){
            s2.pop();
        }
        for(int i=1;i<=ttttt;i++){
            s1.push(make_pair(a[i],c[i]));
        }
        for(int i=n;i>=ttttt+1;i--){
            s2.push(make_pair(a[i],c[i]));
        }
        work();
    }
    else{
        while(!s1.empty()){
            s1.pop();
        }
        while(!s2.empty()){
            s2.pop();
        }
        sol();//kuai duoy dang midc
        for(int i=1;i<=kuai;i++){
            s1.push(make_pair(a[i],c[i]));
        }
        for(int i=n;i>=kuai+2;i--){
            s2.push(make_pair(a[i],c[i]));
        }
        int temp=min(duoy,dang-duoy),ll=duoy,rr=dang-duoy;
        ll-=temp;
        rr-=temp;
        //ans+=temp;
        if(ll!=0){
            s1.push(make_pair(ll,midc));
        }
        if(rr!=0){
            s2.push(make_pair(rr,midc));
        }
        work();
    }
    cout<<ans;
    return 0;
}
