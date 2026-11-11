#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    vector<int> aa(n+1);
    vector<int> ans(m+1);
    vector<int> last(m+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        aa[i]=a[i];
        if(last[a[i]]==0)last[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
           if(last[a[j]]!=0){
                for(int k=last[a[j]]+1;k<=n;k++){
                    aa.pop_back();
                }
           }else{
               aa.push_back(a[j]);
           }
           for(int k=1;k<=m;k++){
                last[k]=0;
           }
           for(int k=1;k<=aa.size();k++){
                last[aa[k]]=k;
           }
        }
        for(int j=1;j<=aa.size();j++){
            ans[aa[j]]++;
        }
        for(int j=1;j<=n;j++){
            aa[j]=a[j];
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
