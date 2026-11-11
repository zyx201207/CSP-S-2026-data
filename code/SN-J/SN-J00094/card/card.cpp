#include<bits/stdc++.h>

using namespace std;

int a[5010];
stack<int>st;
bool c[5010];
int cnt[5010];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        memset(c,0,sizeof(c));
        while(!st.empty())st.pop();
        for(int j = i;j <= n;j++){
            if(c[a[j]]==0){
                c[a[j]] = 1;
                st.push(a[j]);
            }else{
                while(st.top()!=a[j]){
                    c[st.top()]=0;
                    st.pop();
                }
            }
        }
        for(int j = 1;j <= m;j++)if(c[j])cnt[j]++;
    }
    for(int i = 1;i <= m;i++){
        cout << cnt[i] << " ";
    }
    return 0;
}
