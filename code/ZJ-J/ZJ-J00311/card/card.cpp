#include <bits/stdc++.h>
#include <queue>
using namespace std;
int n,m,a[500005],b[500005],c[500005],d[500005];
queue<int> q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int j=1;j<=n;j++){
        for(int i=j;i<=n;i++){
            int x;
            x=c[i];
            q.push(x);
            a[x]++;
            if(a[x]>1){
                int e=1;
                while(q.front()!=x){
                    int s=q.front();
                    d[e]=s;
                    q.pop();
                    e++;

                }
                a[x]--;
                q.pop();
                int f=1;
                while(q.front()!=x){
                    int s=q.front();
                    a[s]--;
                    q.pop();
                    f++;

                }
                for(int i=1;i<=e;i++){
                    q.push(d[i]);
                    d[i]=0;
                }
                for(int i=1;i<=j-e-f;i++){
                    int r=q.front();
                    q.pop();
                    q.push(r);
                }
                e=0;
            }

        }
        for(int i=1;i<=m;i++){
            if(a[i]){
                b[i]++;
                a[i]=0;

            }
        }
        while(!q.empty()){
            q.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }

    return 0;
}
