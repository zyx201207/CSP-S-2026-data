#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500005];
int ans[300005];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=n;i>=1;i--){
        stack<int> x;
        map<int,bool> mm;

        for(int j=i;j<=n;j++){
            if(mm.find(a[j])==mm.end()){
                x.push(a[j]);
                mm[a[j]]=true;
            }else{
                while(!x.empty()&&x.top()!=a[j]){
                    mm.erase(x.top());
                    x.pop();
                }
            }
        }
        while(!x.empty()){
            ans[x.top()]++;
            //cout<<x.top()<<" ";
            x.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
