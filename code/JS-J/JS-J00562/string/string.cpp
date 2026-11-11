#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int N = 1e6+10;

int n;
pair<int,char> a[N];
char s[1];
int c[N],d[N];
set<int> st;
pair<int,char> f[N];
int rear = 0;
int ans = 0;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    c[0] = 0;
    for (int i = 1;i <= n;i++){
        s[0] = 0;
        scanf("%lld%s",&a[i].first,s);
        a[i].second = s[0];
        c[i] = c[i-1]+a[i].first;
    }
    d[n+1] = 0;
    for (int i = n;i >= 1;i--){
        d[i] = d[i+1]+a[i].first;
    }
    //printf("111111111\n");
    int r = n;
    for (int i = 1;i <= n;i++){
        st.insert(c[i]);
        st.insert(c[n]-c[i]);
    }
    //printf("%lld\n",ll(st.size()));
    st.erase(0);
    int id = 1;
    int las = 0;
    for (auto y : st){
        
        while (c[id] < y && id <= n){
            id++;
        }
        if (id > n){
            break;
        }
        //printf("(%lld %lld) ",y,id);
        f[++rear] = {y-las,a[id].second};
        las = y;
    }
    //printf("\n");
    for (int i = 1,j = rear;i <= j;i++,j--){
        if (f[i].second != f[j].second){
            ans += f[i].first;
        }
       // printf("%lld %lld %c\n",i,f[j].first,f[i].second);  
    }
    printf("%lld\n",ans);

    //printf("%lld\n",ll(st.size()));

    return 0;
}