
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n;
    int m;
    cin>>n>>m;
    vector<int> d(n+5);
    vector<int> ans(m+5);
    for(int j=1;j<=n;j++) cin>>d[j];
    int i=1;
    while(i<=n){
        vector<int> b(m+5);
        for(int j=0;j<=m;j++) b[j]=0;
       stack<int> a;
        for(int j=i;j<=n;j++){
            if(b[d[j]]==0){
                a.push(d[j]);
                b[d[j]]=1;
            }
            else{
                  while(a.top()!=d[j]) a.pop();
            }
        }
        while(!a.empty()){
            ans[a.top()]++;
            a.pop();
        }
    i++;
    }
    cout<<ans[1];
    for(int i=2;i<=m;i++){
        cout<<" "<<ans[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
