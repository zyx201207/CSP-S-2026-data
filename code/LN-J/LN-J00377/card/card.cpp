#include<bits/stdc++.h>
using namespace std;
int n,a[5000],p[5000];
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
        for(int j=i;j<=n;j++){
            int cnt=0;
            int cnt2=0;
            bool flag=0;
            int changdu=q.size();
            for(int k=1;k<=changdu;k++){
                cnt++;
                if(q.front()==a[j]){
                    flag=1;
                    cnt2=cnt;
                }
                int x=q.front();
                q.pop();
                q.push(x);
            }
            if(flag==1){
                for(int k=1;k<=cnt2+1;k++){
                    q.pop();
                }
            }
            q.push(a[j]);
        }
        int v=q.size();
        for(int j=1;j<=v;j++){
            int b=q.front();
            p[b]++;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<p[i]<<" ";
    }
}

