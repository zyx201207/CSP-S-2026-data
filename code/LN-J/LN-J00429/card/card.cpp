#include<bits/stdc++.h>
using namespace std;
int a[500005];
int cnt[300005];
bool f[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        queue<int> q;
        queue<int> s;
        queue<int> ct;
        memset(f,0,sizeof(f));
        for(int j=i;j<=n;j++){
            bool f=0;
            while(!q.empty()){
                int no=q.front();
                q.pop();
                ct.push(no);
                s.push(no);
                if(no==a[j]){
                    f=1;
                    s.pop();
                    break;
                }
            }
            if(!f){
                while(!q.empty()){
                    q.pop();
                }
                while(!ct.empty()){
                    int no=ct.front();
                    ct.pop();
                    q.push(no);
                }
            }else{
                while(!q.empty()){
                    q.pop();
                }
                while(!s.empty()){
                    int no=s.front();
                    s.pop();
                    q.push(no);
                }
            }
            q.push(a[j]);
        }
        while(!q.empty()){
            int no=q.front();
            q.pop();
            if(!f[no]){
                cnt[no]++;
            }
            f[no]=1;
            //cout<<no<<" ";
        }
        //cout<<'\n';
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
