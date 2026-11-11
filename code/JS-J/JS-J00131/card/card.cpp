#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=5e5+10;
int n,m,a[N];
int ans[N];
int las[N];
bool vh[N];
void work1(){
    for(int p=1;p<=n;++p){
        stack<int>q;
        for(int i=p;i<=n;++i){
            if(vh[a[i]]){
                while(q.top()!=a[i]){
                    vh[q.top()]=0;
                    q.pop();
                }
                q.pop();
            }
            q.push(a[i]);
            vh[a[i]]=1;
        }
        for(int i=1;i<=m;++i){
            if(vh[i]){
                ans[i]++;
            }
            vh[i]=0;
        }
    }
    for(int i=1;i<m;++i){
        cout<<ans[i]<<" ";
    }
    cout<<ans[m]<<endl;
}
void work2(){
    for(int i=1;i<=n;++i){
        if(a[i+1]!=a[i]){
            ans[a[i]]=n-i;
        }
    }
    for(int i=1;i<=m;++i){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    if(n*n<=1e8){
        work1();
    }else{
        work2();
    }
    return 0;
}