#include <bits/stdc++.h>
using namespace std;
const int N=200005;
typedef long long ll;
ll a[N];
char c[N];
ll len,pre;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        len+=a[i];
    }
    stack<pair<ll,char>>st,st2;
    ll ans=0;
    int i=0;
    while(1){
        pre+=a[i];
        if(pre>len/2){
            pre-=a[i];
            a[i]-=len/2-pre;
            st.push({len/2-pre,c[i]});
            st2.push({len/2-pre,c[i]});
            break;
        }
        st.push({a[i],c[i]});
        st2.push({a[i],c[i]});
        i++;
    }
//    cout<<i<<'\n';
//    while(!st2.empty()){
//        cout<<st2.top().first<<' '<<st2.top().second<<"\n";
//        st2.pop();
//    }
    if(len%2) a[i]--;
    while(i<n){
        int now=a[i];
        while(!st.empty()&&st.top().first<=now){
            now-=st.top().first;
            ans+=(st.top().second!=c[i])*st.top().first;
            st.pop();
        }
        if(now){
            st.top().first-=now;
            ans+=(st.top().second!=c[i])*now;
        }
        i++;
    }
    cout<<ans;
    return 0;
}
