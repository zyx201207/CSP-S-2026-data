#include <bits/stdc++.h>
using namespace std;
int n,m,a[50010],b[50010];
queue<int>q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >>a[i];
    }
    int c[50010]={};
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){

            q.push(a[j]);
            c[a[j]]+=1;
            if(c[a[j]]>1){

                while(q.front()!=a[j]){

                    q.push(q.front());
                    q.pop();

                }
                c[a[j]]--;
                q.pop();
                while(q.front()!=a[j]){

                    c[q.front()]--;
                    q.pop();

                }
            }
        }
        while(!q.empty()){
            b[q.front()]++;
            c[q.front()]--;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout << b[i]<<" ";
    }
    return 0;
}
