#include<bits/stdc++.h>
using namespace std;
int n,m,a[500009],res[300009];
bool v[300009];
stack<int>st;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }for(int i=1;i<=n;i++){
        memset(v,0,sizeof v);
        while(st.size()) st.pop();
        for(int j=i;j<=n;j++){
            if(v[a[j]]){
                int s=st.top();
                while(s!=a[j]){
                    st.pop();
                    v[s]=0;
                    s=st.top();
                }st.pop();
                st.push(a[j]);
                v[a[j]]=1;
            }else{
                st.push(a[j]);
                v[a[j]]=1;
            }
        }for(int j=1;j<=m;j++){
            if(v[j]){
                res[j]++;
            }
        }
    }for(int i=1;i<=m;i++){
        printf("%d ",res[i]);
    }return 0;
}
