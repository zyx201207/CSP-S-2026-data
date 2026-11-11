#include<bits/stdc++.h>
using namespace std;
int a[5010],wz[3010];
bool flag[3010];
stack <int> st;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(flag[a[j]]==0){
                st.push(a[j]);
                flag[a[j]]=1;
                wz[a[j]]=j;
            }
            else{
                for(int k=wz[a[j]]+1;k<=st.size();k++){
                    st.pop();
                }
            }
        }
    }
    return 0;
}
