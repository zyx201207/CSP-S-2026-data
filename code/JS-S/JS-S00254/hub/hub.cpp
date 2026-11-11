#include<bits/stdc++.h>
using namespace std;
int cnt[10101];
struct node{
int cnt,id;
}asd[90909];
bool cmp(node s,node d){
return s.cnt>d.cnt;}
int main(){
freopen("hub.in","r",stdin);
freopen("hub.out","r",stdout);
int c,t;
int n,k;
cin>>c>>t;
while(t--){
        for(int i=1;i<=n;i++)cnt[i]=0;
    cin>>n>>k;
    int ans[10101];
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        node[x].cnt++;
                node[y].cnt++;
node[x].id=x;
node[y]id=y;


    }
    sort(asd+1,asd+1+n,cmp);
    for(int i=1;i<=k;i++)ans[i]=asd[i].id;
    cout<<1<<"\n";
}
return 0;
}
