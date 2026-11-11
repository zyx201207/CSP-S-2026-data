#include<bits/stdc++.h>
using namespace std;

int n,m,a[500005];
map<int,int>mp;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
    stack<int>q;
    map<int,int>mp2;
        for(int j=i;j<=n;j++){
            if(mp2[a[j]]==0){
                q.push(a[j]);
                mp2[a[j]]++;
            }
            else{
                while(q.top()!=a[j]){
                    mp2[q.top()]--;
                    q.pop();
                }
            }
        }
        while(!q.empty()){
        mp[q.top()]++;
        q.pop();
        }
    }
   for(int i=1;i<=m;i++){
        cout<<mp[i]<<" ";
    }
    return 0;
}
