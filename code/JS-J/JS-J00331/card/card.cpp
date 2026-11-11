#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[500005];
int check[5005][2];
int sum[500005];
bool tf[500005];
queue<int>q;
int main(){
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        int k=i-1;
        while(k!=n){
            if(check[arr[k]][0]==0){
                q.push(arr[k]);
                check[arr[k]][0]=1;
                check[arr[k]][1]=k;
            }
            if(check[arr[k]][0]==1){
                for(int j=0;j<(k-check[arr[k]][1]);j++){
                    q.pop();
                }
                q.push(arr[k]);
                check[arr[k]][1]=k;
            }
            k++;
        }
        while(!q.empty()){
            int f=q.front();
            q.pop();
            if(tf[f]==0){
                tf[f]=1;
                sum[f]++;
            }
        }
        memset(tf,0,sizeof(tf));
        memset(check,0,sizeof(check));
    }
    for(int i=1;i<=m;i++){
        cout<<sum[i]<<' ';
    }
    return 0;
}
