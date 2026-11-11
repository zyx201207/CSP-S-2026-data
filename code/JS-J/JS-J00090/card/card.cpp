#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
map<int,int>ans;
bool sch(vector<int>x,int y){
    for(int k=0;k<x.size();k++)
        if(x[k]==y)
            return 1;
    return 0;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> a[i];
    for(int i=1;i<=n;i++){
        vector<int>v;
        for(int j=i;j<=n;j++){
            int x=a[j];
            if(!sch(v,a[j])){
                reverse(v.begin(),v.end());
                v.push_back(a[j]);
                reverse(v.begin(),v.end());
            }
            else{
                vector<int>l;
                int t=0;
                for(int k=0;k<v.size();k++){
                    if(v[k]==a[j])t=k;
                }
                for(int k=i;k<v.size();k++)l.push_back(v[k]);
                l.push_back(a[j]);
                v=l;
                reverse(v.begin(),v.end());
            }
        }
        for(int j=0;j<v.size();j++)ans[v[j]]++;
    }
    for(int i=1;i<=m;i++)cout << ans[i] << " ";
}
//RP++
