#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N=5e5+10;
int ans[N];
bool f[N];
int a[N];
int n,m;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n>500){
        int i=1;
        for(;i<=n;i++){
            while(a[i]==a[i+1])i++;
            ans[a[i]]=i;
        }
        for(int i=1;i<=m;i++){
            cout<<ans[i]<<" ";
        }
        return 0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            f[i]=1;
        }
        for(int i=k+1;i<=n;i++){
            for(int j=i-1;j>=k;j--){
                if(a[i]==a[j]&&f[j]){
                    for(int l=i-1;l>=j;l--)f[l]=0;
                }
            }
        }
        for(int i=k;i<=n;i++){
            if(f[i])ans[a[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
