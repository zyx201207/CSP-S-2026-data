#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1000;
int n,m;
int a[N];
stack<int> q;
bool vis[N];
int s[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(!vis[a[j]]){
                vis[a[j]]=true;
                q.push(a[j]);
            }
            else {
                while(q.top()!=a[j])q.pop();
            }
        }
        while(!q.empty()){
            s[q.top()]++;
            q.pop();
        }
    }
    for(int i=1;i<=n;i++)
        cout<<s[i]<<" ";
	return 0;
}
