#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define lf double
void op(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
}
const ll maxn=5e5+25;
ll n,m;
ll a[maxn];
bool bj[maxn];//BJ Shi4fou3 Cun2zai4
ll ans[maxn];
stack<ll>st;
int main(){
    op();
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;++i){
        scanf("%lld",&a[i]);
    }
    for(ll i=1;i<=n;++i){
        for(ll j=i;j<=n;++j){
            if(bj[a[j]]==1){
                while(st.top()!=a[j]){
                    bj[st.top()]=0;
                    st.pop();
                    if(!st.empty()){
                        break;
                    }
                }
            }else{
                st.push(a[j]);
                bj[a[j]]=1;
            }
        }
        for(ll j=1;j<=m;++j){
            ans[j]+=bj[j];
            bj[j]=0;
        }
        while(!st.empty()){
            st.pop();
        }
    }
    for(ll i=1;i<=m;++i){
        printf("%lld ",ans[i]);
    }
    return 0;
}
/*
abcdefghijklmnopqrstuvwxyz
1234567890
~!@#$%^&*()-=_+`/,.<>\{}[];':"
operator
*/
