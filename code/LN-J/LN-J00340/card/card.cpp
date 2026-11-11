#include<bits/stdc++.h>
using namespace std;
int n,m,ans[10086],a[10086];
bool flag[10086];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int k=1;k<=n;k++){
        cout<<"di "<<k<<":"<<endl;
        for(int i=1;i<=m;i++)flag[i]=false;
        for(int i=k,j=n;i<=j;){
            ans[a[i++]]++;
            flag[a[i]]=true;
            cout<<a[i]<<" ";
            if(flag[a[i]]&&flag[a[j]]){
                ans[a[i]]--;
                break;
            }
            ans[a[j++]]++;
            flag[a[j]]=true;
            cout<<a[j]<<" ";
            if(flag[a[i]]&&flag[a[j]]){
                ans[a[j]]--;
                break;
            }

        }
        cout<<endl;
    }
    for(int i=1;i<m;i++)cout<<ans[i]<<" ";
    cout<<ans[m];
    return 0;
}
