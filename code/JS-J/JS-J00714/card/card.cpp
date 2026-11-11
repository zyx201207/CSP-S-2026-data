#include<bits/stdc++.h>
using namespace std;
stack<int> s;
bool exist[100005];
int a[100005],ans[100005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int i=1;i<=m;i++){
            exist[i]=0;
        }
        while(!s.empty()){
            s.pop();
        }
        for(int j=i;j<n;j++){
            if(exist[a[j]]){
                while(s.top()!=a[j]){
                    exist[s.top()]=0;
                    s.pop();
                }
                s.pop();
                exist[a[j]]=0;
            }
            s.push(a[j]);
            exist[a[j]]=1;
        }
        for(int j=1;j<=m;j++){
            ans[j]+=exist[j];
        }
    }
    for(int j=1;j<=m;j++){
        cout<<ans[j]<<" ";
    }
}
