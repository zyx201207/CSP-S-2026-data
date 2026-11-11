#include <bits/stdc++.h>
using namespace std;
int n=0,m=0,x,it=0,ans=0;
vector<int>a;
int lef(int v,int b){
    int l=m,j=0;
    for(int i=b;i>=0;i--){
        if(a[i]>v)continue;
        if(a[i]==v){
            j++;
            continue;
        }
        if(l>=v-a[i]){
            l-=v-a[i];
            j++;
            continue;
        }
        return j;
    }
    return j;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    int bl=a[2]-a[1];

    for(int i=a.size()-1;i>=0;i--){
        ans=max(ans,lef(a[i],i));
    }
    cout<<ans;
    return 0;
}
