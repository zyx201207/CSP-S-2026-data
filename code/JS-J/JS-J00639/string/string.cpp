#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
ll L=0;
ll n;
ll a[MAXN];
char c[MAXN];
queue<pair<ll,char> >q1,q2;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        L+=a[i];
    }
    ll len=L/2;
    ll l1=0,l2=0,idx1=1,idx2=n;
    while(1){
        if(l1+a[idx1]>len){
            q1.push({len-l1,c[idx1]});
            l1+=len-l1;
        }else{
            q1.push({a[idx1],c[idx1]});
            l1+=a[idx1];
        }
        idx1++;
        if(l1==len)
            break;
    }
    while(1){
        if(l2+a[idx2]>len){
            q2.push({len-l2,c[idx2]});
            l2+=len-l2;
        }else{
            q2.push({a[idx2],c[idx2]});
            l2+=a[idx2];
        }
        idx2--;
        if(l2==len)
            break;
    }//cout<<'\n';
    // while(!q1.empty()){
    //     cout<<q1.front().first<<' '<<q1.front().second<<'\n';
    //     q1.pop();
    // }cout<<'\n';
    // while(!q2.empty()){
    //     cout<<q2.front().first<<' '<<q2.front().second<<'\n';
    //     q2.pop();
    // }cout<<'\n';
    ll ans=0;
    l1=0;
    l2=0;
    char c1=' ',c2=' ';
    while(!q1.empty()||!q2.empty()){
        if(!l1){
            l1=q1.front().first;
            c1=q1.front().second;
            q1.pop();
        }
        if(!l2){
            l2=q2.front().first;
            c2=q2.front().second;
            q2.pop();
        }
        //cout<<l1<<" "<<l2<<" ";
        if(l1==l2){
            if(c1!=c2)
                ans+=l1;
            l1=l2=0;
        }else{
            if(l1>l2){
                if(c1!=c2)
                    ans+=l2;
                l1-=l2;
                l2=0;
            }else{
                if(c1!=c2)
                    ans+=l1;
                l2-=l1;
                l1=0;
            }
        }
        //cout<<ans<<'\n';
    }
    cout<<ans;
    return 0;
}
//g++ string.cpp -o string -std=c++14 -O2