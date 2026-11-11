#include<bits/stdc++.h>
using namespace std;
const int N = 300005;
long long n,m;
long long a[N];
long long ans[N];
stack<long long>st;
bool mp[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(long long i = 1;i <= n;i++){
        memset(mp,false,sizeof(mp));
        for(long long j = i;j <= n;j++){
            if(mp[a[j]] == 0){
                st.push(a[j]);
                mp[a[j]] = 1;
            }
            else{
                while(!st.empty() && st.top() != a[j]){
                    st.pop();
                }
            }
        }
        do{
            ans[st.top()]++;
            st.pop();
        }while(!st.empty());
    }
    for(long long i = 1;i <= m;i++){
        cout << ans[i] << " ";
    }
    return 0;
}
