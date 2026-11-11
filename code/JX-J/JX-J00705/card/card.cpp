#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    queue<int> a,desk;
    vector<int> num;
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a.push(x);
    }
    for(int k=1;k<=n;k++){
        for(int i=k;i<=n;i++){
            if(!desk.empty()&&a.front()==desk.front()){
                while(!desk.empty()){
                    desk.pop();
                }
            }
            desk.push(a.front());
            a.pop();
        }
        while(!desk.empty()){
            num.push_back(desk.front());
            desk.pop();
        }
    }
    int ans[m+5];
    memset(ans,0,a.size());
    for(int i=1;i<=m;i++){
        for(int j=0;j<num.size();j++){
            if(i==num[j]){
                ans[i]++;
            }
        }
        cout<<ans[i]<<" ";
    }
    return 0;
}
