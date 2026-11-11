#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=200010;
struct node{
    char c;
    ll a;
}t[N];
ll n,sum=0,ans=0;
stack<node> st;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>t[i].a>>t[i].c,sum+=t[i].a;
    if(sum%2==1){
        ll l=0;
        for(int i=1;i<=n;i++){
            l+=t[i].a;
            if(l>=(sum+1)/2){
                t[i].a--;
                break;
            }
        }
        sum--;
    }
    ll l=0,k=0;
    for(k=1;k<=n;k++){
        l+=t[k].a;
        st.push(t[k]);
        if(l>sum/2){
            break;
        }
    }
    t[k].a=l-sum/2;
    st.top().a-=l-sum/2;
    //cout<<k<<"\n";
    for(k;k<=n;k++){
        //cout<<k<<"\n";
        while(st.size()>0&&t[k].a-st.top().a>=0){
            //cout<<st.top().a<<" "<<t[k].a<<"\n";
            if(st.top().c!=t[k].c) ans+=st.top().a;
            t[k].a-=st.top().a;
            st.pop();
        }
        if(st.size()){
            //cout<<" "<<st.top().a<<" "<<t[k].a<<"\n";
            if(st.top().c!=t[k].c) ans+=t[k].a;
            st.top().a-=t[k].a;
        }
        
    }
    cout<<ans;
    return 0;
}