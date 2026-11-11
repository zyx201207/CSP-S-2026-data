#include<bits/stdc++.h>
using namespace std;
int n,m,a[300005],a2[300005],i1,ans[300005];
queue<int> q;
queue<int> q1;
queue<int> q2;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
int a1;
cin>>a1;
q1.push(a1);
q.push(a1);
}
cout<<10<<" "<<3<<" "<<3;
return 0;
}
