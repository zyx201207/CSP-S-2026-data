#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int cnt[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    queue<int >q,q1;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            while(!q.empty()){
                if(q.front()==a[j]){
                    break;
                }
                q1.push(q.front());
                q.pop();
            }
            while(!q.empty()){
                q.pop();
            }
            while(!q1.empty()){
                q.push(q1.front());
                q1.pop();
            }
            q.push(a[j]);

    }
            while(!q.empty()){
                cnt[q.front()]++;
                q.pop();
            }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
