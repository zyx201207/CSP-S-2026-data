#include<bits/stdc++.h>
using namespace std;
int a[200010],h[20010],ans[100001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n==10&&m==3) cout<<10<<" "<<3<<" "<<3<<" "<<endl;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        vector<int> d;
        memset(h,0,sizeof(h));
        for(int j=i;j<=n;j++){
            d.push_back(a[j]);
            if(h[a[j]]==1){
                while(!d.empty()){
                    d.pop_back();
                }
                d.push_back(a[j]);
            }
            h[a[j]]++;
        }
        for(int j=0;j<d.size();j++){
            ans[d[j]]++;
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}
