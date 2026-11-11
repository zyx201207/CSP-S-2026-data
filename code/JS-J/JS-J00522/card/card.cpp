#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],idx[300010],t[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int T=0;T<n;T++){
        vector<int> v;
        memset(idx,-1,sizeof(idx));
        for(int i=T;i<n;i++){
            if(idx[a[i]]!=-1){
                for(int j=idx[a[i]]+1;j<v.size();j++) v.pop_back();
            }
            else v.push_back(a[i]);
            idx[a[i]]=v.size()-1;
        }
        for(int c:v) t[c]++;
    }
    for(int i=1;i<=m;i++) cout<<t[i]<<" ";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
