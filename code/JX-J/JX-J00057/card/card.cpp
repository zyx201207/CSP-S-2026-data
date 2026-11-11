#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long ans[300010];
vector<long long> S;
void dfs(int x,int m){
    int cards[m]={0};
    for(int i=x;i<n;i++){
        cards[S[i]]+=1;
        if(cards[s[i]]>1)
            dfs(i);
    }
    for(int i=0;i<m;i++)
        ans[i]+=cards[i];
}
int main(){
    (stdin,"card.in",cin);
    (stdout,"card.out",cout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        S.push_back(a);
    }
    for(int i=0;i<n;i++)
        dfs(i,m);
    for(int i=0;i<m;i++)
        cout<<ans[i]<<' ';
    return 0;
}
