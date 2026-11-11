#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    map<int,int> mpp;
    for(int i=1;i<=n;i++){
        queue<int> q,q2;
        map<int,int> mp;
        for(int j=i;j<=n;j++){
            if(!mp[a[j]]){
                q.push(a[j]);
                mp[a[i]]++;
            }else{
                while(q.size()){
                    if(q.front()==a[j]){
                            q2.push(a[j]);
                            break;
                    }
                    q2.push(q.front());
                    q.pop();
                }
                while(q.size()){
                    q.pop();
                }
                while(q2.size()){
                    q.push(q2.front());
                    q2.pop();
                }
            }
        }
        while(q.size()){
            cout<<q.front()<<" ";
            mpp[q.front()]++;
            q.pop();
        }
        cout<<'\n';
    }
    for(int i=1;i<=m;i++){
        cout<<mpp[i]<<" ";
    }
    return 0;
}
