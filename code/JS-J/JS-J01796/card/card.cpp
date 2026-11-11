#include<bits/stdc++.h>
using namespace std;
int a[500010],sum[300010];
int main(){

    freopen("card,in","r",stdin);
    freopen("card.out","w",stdout);

    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int cnt[m+5]{};
        stack<int> s;
        for(int j=i;j<=n;j++){
           if(cnt[a[j]]==0){
                cnt[a[j]]++;
                s.push(a[j]);
           }else{
                while(s.top()!=a[j]){
                    cnt[s.top()]--;
                    s.pop();
                }

           }

        }
        for(int x=1;x<=m;x++){
            if(cnt[x]>0){
                sum[x]++;
            }

        }

    }

    for(int i=1;i<=m;i++){
        cout<<sum[i]<<" ";
    }
    return 0;
}
