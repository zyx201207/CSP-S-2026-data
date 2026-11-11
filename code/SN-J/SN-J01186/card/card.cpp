#include<bits/extc++.h>
using namespace std;
int n,m,a[500005];
__gnu_pbds::gp_hash_table<int,int> h;
__gnu_pbds::gp_hash_table<int,bool> ins;
deque<int> st;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(ins[a[j]]){
                while(!st.empty()&&st.back()!=a[j]){
                    st.pop_back();
                }
            }else{
                st.push_back(a[j]);
                ins[a[j]]=1;
            }
        }
        for(auto i:st){
            h[i]++;
        }
        st.clear();
        for(int j=1;j<=n;j++){
            ins[a[j]]=0;
        }
    }
    for(auto i:h){
        printf("%d ",i.second);
    }
    return 0;
}
