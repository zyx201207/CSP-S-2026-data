#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[5005];
int ans[5005];
vector<int>v;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(int k:v){
                ans[k]++;
            }
            for(int k=0;k<v.size();k++){
                if(v[k]==a[j]){
                    for(int p=v.size()-1;p>k;p++){
                        v.pop_back();
                    }
                }
            }
        }
        v.clear();
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
