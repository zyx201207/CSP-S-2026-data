#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001];
int b[1001];
void mn(int k){
    stack <int> s;
    set <int> t;
    for(int i=k;i<=n;i++){
        s.push(a[i]);
        if(t.count(a[i])!=0){
            s.pop();
            while(1){
                if(s.top()==a[i]) break;
                s.pop();
            }
            t.erase(a[i]);
        }
        else{
            t.insert(a[i]);
        }
    }
    while(!s.empty()){
        b[s.top()]++;
        s.pop();
    }

}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        mn(i);
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<' ';
    }
    return 0;
}
