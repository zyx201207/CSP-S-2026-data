#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m,a[11000000];
    cin>>n>>m;
    vector<long long> v;
    queue<long long> q;
    for(long long i=0;i<n;i++){
        long long a;
        cin>>a;
        q.push(a);
    }
    for(long long i=1;i<=n;i++){
        while(q.size()>1){
            long long k=q.front();
            bool f=0;
            q.pop();
            for(long long j=0;j<v.size();j++){
                if(v[j]==k){
                    f==1;
                    break;
                }
            }
            if(f){
                while(v.front()!=k){
                    v.pop_back();
                }
                v.pop_back();
            }
            v.push_back(k);
        }
        while(!v.empty()){
            long long k=v.front();
            a[k]++;
            v.pop_back();
        }

    }
    for(long long i=1;i<=m;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
