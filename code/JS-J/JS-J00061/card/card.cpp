#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[500005],b[500005];
    stack<int>s;
    set<int>t;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=0;
    }
    for(int i=0;i<m;i++){
        cout<<n<<' ';
        return 0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(t.count(a[j])>0){
                int tp;
                while(tp!=a[j]){
                    tp=s.top();
                    if(tp==a[j])break;
                    else{
                        s.pop();
                    }
                }
            }
            else{
                s.push(a[j]);
                t.insert(a[j]);
            }

        }
        while(!s.empty()){
            b[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<' ';
    }
    return 0;
}
