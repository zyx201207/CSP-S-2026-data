#include<bits/stdc++.h>
using namespace std;
int n,m,s[300005],a[500005];
int sum[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        sum[a[i]]=i;
        if(s[a[i]]>0){
            for(int j=i;j>a[i];j--){
                sum[j]--;
            }
        }
        else{
            s[a[i]]=1;
        }
    }

    for(int i=1;i<=300005;i++){
        if(sum[i]!=0){
            cout<<sum[i]<<' ';
        }
    }
    return 0;
    }
