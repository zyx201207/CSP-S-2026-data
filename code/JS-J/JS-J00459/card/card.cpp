#include<bits/stdc++.h>
using namespace std;
int a[500010],t[500010],x[300010],ans[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n,m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t[i]=a[i];
    }
    for(int i=n;i>=1;i--){
        x[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int c=a[j];
            if(x[a[j]]>j){
                while(a[j]!=c&&j!=x[a[j]]){
                    a[j]=0;
                    j++;
                }
            }
        }
        for(int j=1;j<=n;j++)
            if(a[j])ans[a[j]]++;
        for(int j=i;j<=n;j++)t[i]=a[i];
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
