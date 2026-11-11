#include<bits/stdc++.h>
using namespace std;
int main () {
freopen("card","r",stdin);
freopen("card","w",stdout);
 stack<int>b;
 stack<int>a;
stack<int>d;
stack<int>e;
 int c[300001];
 int n;
 int m,top=0,pop=0;
 cin>>n>>m;
 for(int i=1;i<=n;i++){
    cin>>c[i];
    a.push(c[i]);
 }
 for(int l=n;l>=1;l--){
    if(b.empty()){
        b.push(c[l]);
        top++;
        a.pop();
    }
    else {
       for(int j=1;j<=top;j++){
          if(b.top()==c[l]){
            for(int i=1;i<=pop;i++){
                e.pop();
            }
            break;
          }
          else {
            d.push(b.top());
            e.push(d.top());
            pop++;
          }
       }
    }
 }
 for(int i=1;i<=top;i++){
    cout<<b.top();
    b.pop();
 }
return 0;
}

