#include<bits/stdc++.h>
using namespace std;
long long n,m,ans[500010],a[500010];
bool occur[300010];
deque<long long > fish;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long j=n;j>=1;j--){
        memset(occur,false,sizeof(occur));
        for(long long i=j;i<=n;i++){
            if(occur[a[i]] == true){
                while(fish.back() != a[i] && !fish.empty()){
                    occur[fish.back()] = false;
                    fish.pop_back();
                }
            }
            else{
                fish.push_back(a[i]);
                occur[a[i]] = true;
            }
        }
        while(!fish.empty()){
            ans[fish.front()]++;
            fish.pop_front();
        }
    }
    for(long long i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
