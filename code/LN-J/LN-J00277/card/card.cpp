#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int>a(n+1);
    //vector<int>c(m+1);
    //vector<int>p(m+1);
    for(int i=1;i<=n;i++){
        int ff;
        cin>>ff;
        a.push_back(ff);
    }
    /*for(int i=1;i<=n;i++){
        stack<int>s;
        for(int j=i;j<=n;j++){
            if(c[a[j]]>=1){
                while(s.top()!=a[j]){
                    c[s.top()]--;
                    s.pop();
                }
            }else{
                s.push(a[j]);
                c[a[j]]=1;
            }
        }
        vector<bool>k(m+1);
        while(!s.empty()){
            if(k[s.top()]==0){
                p[s.top()]+=1;
                k[s.top()]=1;
            }
            s.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<p[i];
    }*/
    for(int i=1;i<=m;i++){
        cout<<0<<" ";
    }
    return 0;
}
