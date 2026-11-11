#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N=5e5+5;
const int M=3e5+5;
int n,m,a[N],ans[M],tong[N];
stack<int>stk;
queue<int>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int T=0;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		T=max(a[i],T);
	}
	for(int i=1;i<=n;i++){
		while(!q.empty())q.pop();
		while(!stk.empty())stk.pop();
		for(int j=1;j<=T;j++)tong[j]=0;
		for(int j=i;j<=n;j++){
			q.push(a[j]);	
		}
		while(!q.empty()){
			int p=q.front();
			q.pop();
			if(tong[p]!=0){
				while(!stk.empty() && tong[p]!=0){
					tong[stk.top()]--;
					stk.pop();
				}
			}
			stk.push(p);
			tong[p]++;
			//cerr<<p<<":"<<tong[p]<<","<<q.size()<<","<<stk.size()<<endl;
		}
		for(int x=1;x<=T;x++){
			if(tong[x]) {
				//cerr<<x<<" "<<ans[x]<<endl;
				ans[x]++;
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}

