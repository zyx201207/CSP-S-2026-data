#include<bits/stdc++.h>
using namespace std;
const int MAXM=3e5+10;
int m,n;
vector<int> a;
bool is_appeared[MAXM];
int cnt[MAXM];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    stack<int>s;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)is_appeared[j]=false;
        for(int j=i-1;j<n;j++){
            if(!is_appeared[a[j]]){
                s.push(a[j]);
                is_appeared[a[j]]=true;
            }
            else{
                while(1){
                    int k=s.top();
                    if(k!=a[j]){
                       s.pop();
                       is_appeared[k]=false;
                    }else{
                        break;
                    }
                }
            }
        }
        while(!s.empty()){
            int t=s.top();
            cnt[t]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
