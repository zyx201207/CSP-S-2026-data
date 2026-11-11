#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
stack<int> s;
bool flag=true;
int n,m,a[maxn],h[maxn],ans[maxn];
void part1(){
    int tmp=a[1];
    for(int i=1;i<=n;i++){
        if(a[i]==tmp)
            continue;
        ans[tmp]=i-1;
        tmp=a[i];
    }
    ans[tmp]=n;
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<" ";
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1])
            flag=false;
    }
    if(flag){
        part1();
        return 0;
    }
    for(int i=1;i<=n;i++){
        memset(h,0,sizeof(0));
        for(int j=i;j<=n;j++){
            if(h[a[j]]==1)
                while(!s.empty() && s.top()!=a[j]){
                    h[s.top()]--;
                    s.pop();
                }
            else{
                h[a[j]]++;
                s.push(a[j]);
            }
        }
        while(!s.empty()){
            h[s.top()]--;
            ans[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
    return 0;
}
