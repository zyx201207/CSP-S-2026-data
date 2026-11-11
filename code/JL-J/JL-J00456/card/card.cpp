#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    stack <int> s;
    int m,n;
    cin>>m>>n;
    int a[n]={0,},sum[m];
    for(int i=1;i<=m;i++){
        cin>>sum[i];
    }
    for(int i=1;i<=m-1;i++){
        for(int j=i;j<=m;j++){
            if(s.empty()){
                s.push(sum[j]);
                continue;
            }
            for(int k=1;k<=m;k++){
                if(sum[k]==sum[j]){
                    for(int q=s.size();q>=k;q--){
                        s.pop();
                    }
                    break;
                }
            }
            s.push(sum[j]);
        }
        for(int w=1;w<=s.size();w++){
            int t=s.top();
            s.pop();
            a[t]++;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
