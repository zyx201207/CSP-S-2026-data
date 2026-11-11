#include<iostream>
#include<stack>
//10:02 wo chang chang zhui yi guo qu zhui yi dao le stack
//10:09 starting testing
//10:16 why is #1 output nothing???????????????
//48pts~=
int n,m,a[500001],ans[500001],nxt[3000001];bool b[300001];std::stack<int> s;
int main(){freopen("card.in","r",stdin);freopen("card.out","w",stdout);std::cin>>n>>m;for(int i=0;i<n;i++){std::cin>>a[i];}for(int i=0;i<n;i++){for(int t=0;t<=m;t++){b[t]=0;}for(int j=i;j<n;j++){if(b[a[j]]==1){while(s.top()!=a[j] && s.size()!=0){b[s.top()]=0;s.pop();}s.pop();}s.push(a[j]);b[a[j]]=1;}while(s.size()!=0){ans[s.top()]++;s.pop();}}for(int i=1;i<=m;i++)std::cout<<ans[i]<<' ';}