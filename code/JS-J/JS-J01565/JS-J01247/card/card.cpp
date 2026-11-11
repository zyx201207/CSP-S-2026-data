#include<bits/stdc++.h>
using namespace std;
int c[500009];
int sum[300009];
stack<int>z;
map<int,bool> mp;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;++j){
            if(!mp[c[j]]){
                z.push(c[j]);
                mp[c[j]]=true;
            }
            else{
                while(!z.empty()){
                    if(z.top()==c[j]){
                        break;
                    }else{
                        mp[z.top()]=false;
                        z.pop();
                    }
                }
            }
        }
        while(!z.empty()){
            sum[z.top()]++;
            z.pop();
        }
        for(int j=1;j<=n;j++){
            mp[c[j]]=false;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<sum[i]<<" ";
    }
    return 0;
}