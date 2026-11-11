#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
const int MAXN=2e5+10;
struct node{
    char ch;
    int num;
}a[MAXN];
vector<char> vec;
int sum;
set<char> st;
signed main(){
    freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);

      cin>>n;
      for(int i=1;i<=n;i++){
            cin>>a[i].num>>a[i].ch;
            sum+=a[i].num;
            st.insert(a[i].ch);
      }
      int tt=st.size();
      if(tt==1){
            cout<<0;
            return 0;
      }
      if(sum<=(int)1e8+1){
         for(int i=1;i<=n;i++){
            for(int j=1;j<=a[i].num;j++){
                vec.push_back(a[i].ch);
            }
         }
         int ans=0;
         int t=vec.size();
         for(int i=0;i<vec.size();i++){
            int tmp=t-i-1;
            if(i>tmp) break;
            if(vec[i]!=vec[tmp]) ans++;
         }
         cout<<ans;
         return 0;
     }
     else{
            int maxx=0;
        for(int i=1;i<=n;i++) maxx=max(maxx,a[i].num);
        int ans=maxx*(tt+1);
        cout<<ans;
     }
    return 0;
}
