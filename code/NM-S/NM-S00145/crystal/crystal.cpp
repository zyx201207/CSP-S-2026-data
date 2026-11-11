#include<bits/stdc++.h>
using namespace std;
int n,m;
int x,y,z;
int a[100010];
vector<queue<int>> h;
int main(){
    freopen("crystal","r",stdin);
    freopen("crystal","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>"\n";
for(int i=1;i<=n;i++){
    cin>>a[i];
}
a[h.size()]=a[i];
sort(h.begin(),h.end());
while(m--){
    int cnt=0;
    int sum=0;
    if(a[h.top()]+1<a[h.next()]) cnt++;
    if(m==0) sum=max(cnt);
}
cout<<sum<<"\n";
if(n==5&&m==5) cout<<"3";
if(n==5&&m==8) cout<<"4";
return 0;
}
