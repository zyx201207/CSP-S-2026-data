#include "bits/stdc++.h"
using namespace std;
#define int long long
int a[500005];
int ans[300005],turn[300005];queue<int> q;
void outputq(){
    for(int i=1;i<=q.size();i++){
        cout<<q.front()<<' ';
        q.push(q.front());
        q.pop();
    }
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        
        // cout<<i<<endl;
        // for(int j=i;j<=n;j++){
        //     for(int k=1;k<=q.size();k++){
        //         bool find=0;
                
        //         if(!q.empty()){
        //             if(q.front()!=a[j] and find==0){
        //                 q.push(q.front());
        //                 q.pop();
        //             }
        //             else if(q.front()==a[j] or find){
        //                 find=1;
        //                 q.pop();                
        //             }
        //         }
        //     }
        //     q.push(a[j]);
        //     cout<<"J"<<j<<"　";
        //     outputq();
        //     cout<<endl;
        // }
        // while (!q.empty())
        // {
        //     ans[q.front()]++;
        //     q.pop();
        // }
        int size=1;
        for(int j=i;j<=n;j++,size++){
            for(int k=size;k>0;k--){
                if(turn[k]==a[j]){
                    size=k;
                    break;
                }
            }
            turn[size]=a[j];
        }
        // cout<<"J"<<i<<" ";
        for(int k=1;k<=size;k++){
            ans[turn[k]]++;
            // cout<<turn[k]<<" ";
        }
        memset(turn,0,sizeof(turn));
        // cout<<endl;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}