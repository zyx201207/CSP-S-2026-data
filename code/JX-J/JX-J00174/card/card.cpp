#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],ans[N];
vector<int> s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int q=-1;
        for(int j=0;j<s.size();j++){
            if(s[j]==a[i]){
                q=j;
                break;
            }
        }
        if(q!=-1){
            for(int k=q;k<s.size();k++){
                s.clear();
            }
        }
        s.insert(a[i]);
        for(int w=0;w<s.size();w++){
            ans[s[w]]++;
        }
    }
    for(int i=0;i<m;i++){
        if(ans[i]!=0)cout<<ans<<" ";
    }
    return 0;
}
