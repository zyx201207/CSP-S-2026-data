#include<cstdio>
#include<stack>
using namespace std;
int n,m,a[500005],cnt[300005] = {0};
stack<int>st;
bool second(int x){
    stack<int>s = st;
    while(!s.empty()){
        if(s.top()==x)
            return true;
        s.pop();
    }
    return false;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 1;i<=n;i++){
        while(!st.empty()){
            st.pop();
        }
        for(int j = i;j<=n;j++){
            if(second(a[j])){
                while(!st.empty()&&st.top()!=a[j]){
                    st.pop();
                }
            }else{
                st.push(a[j]);
            }
        }
        while(!st.empty()){
            cnt[st.top()]++;
            st.pop();
        }
    }
    for(int i = 1;i<=m;i++){
        if(i!=1)
            printf(" ");
        printf("%d",cnt[i]);
    }
    printf("\n");
    return 0;
}
