#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500055;
int n,m,a[N],ans[N],b[N],r[N];
stack<int> st;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=5000){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)b[j]=0;
        for(int j=i;j<=n;j++){
            if(b[a[j]]){
                while(1){
                    int x=st.top();
                    st.pop();
                    b[x]--;
                    if(x==a[j])break;
                }
            }
            st.push(a[j]);
            b[a[j]]++;
        }
        while(st.size()){
            int x=st.top();
            st.pop();
            ans[x]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    }
    else{
        for(int i=n;i>=1;i--){
        if(!r[a[i]])r[a[i]]=i;
        for(int j=i;j<=n;j++){
            ans[a[j]]++;
            j=r[a[j]];
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    }
    return 0;
}
