#include<bits/stdc++.h>
#define int __int128_t
#define putchar putchar_unlocked
#define getchar getchar_unlocked
using namespace std;
const int N=5e5+5;
int n,k,arr[N];
int nd,ans=1;
queue<int>st;
void read(int &x){
    x=0;int f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-')f=-f;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    x*=f;
}
void put(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>=10)put(x/10);
    putchar(char(x%10+'0'));
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    read(n);read(k);
    for(int i=1;i<=n;i++)read(arr[i]);
    sort(arr+1,arr+n+1);
    st.push(1);
    for(int i=2;i<=n;i++){
        nd=nd+(st.size()*(arr[i]-arr[i-1]));
        while(nd>k){
            nd-=(arr[i]-arr[st.front()]);
            st.pop();
        }
        st.push(i);
        ans=max(ans,int(st.size()));
    }
    put(ans);
    return 0;
}
