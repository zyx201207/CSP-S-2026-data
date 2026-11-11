#include<bits/stdc++.h>
using namespace std;
queue<int>q;
int n,m;
int a[500005];
int cnt[300005];
void check(int st){
    queue<int>awhile;
    while(!q.empty()){
        if(q.front()==st){
            while(!q.empty()){
                q.pop();
            }
        }
        else{
            awhile.push(q.front());
            q.pop();
        }
    }
    while(!awhile.empty()){
        q.push(awhile.front());
        awhile.pop();
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            check(a[j]);
            q.push(a[j]);
        }
        while(!q.empty()){
            cnt[q.front()]++;
            q.pop();
        }
    }
    for(int i=1;i<m;i++)cout<<cnt[i]<<" ";
    cout<<cnt[m];
    cout<<endl;
    return 0;
}
