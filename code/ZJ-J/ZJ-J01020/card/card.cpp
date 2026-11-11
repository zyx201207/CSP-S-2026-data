#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int a[N],ans[N];
stack<int>p;
int s[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int T=1;T<=n;T++){
        for(int i=1;i<=m;i++)s[i]=0;
        for(int i=T;i<=n;i++){
            s[a[i]]++;
            while(s[a[i]]>=2){
                int r=p.top();
                s[r]--;
                p.pop();
            }
            p.push(a[i]);
        }
        while(!p.empty()){
            int r=p.top();
            ans[r]++;
            p.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i];
        if(i!=m)cout<<" ";
    }
}
//O(N^2) 12*4=48pt in 10:40