#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<int> d(m+1);
    stack<int>s;
    for(int i=1;i<=n;i++){
        vector<bool> c(m+1);
        for(int j=1;j<=n;j++){
            if(c[a[j]]){
                while(s.top()!=a[j]){
                    s.pop();
                    c[s.top()]=0;
                }
                s.pop();
                c[a[j]]=0;
            }
            s.push(a[j]);
            c[a[j]]=1;
        }
        for(int k=1;k<=m;k++){
            if(c[a[k]]==1) d[a[k]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<d[a[i]]<<" ";
    }
}