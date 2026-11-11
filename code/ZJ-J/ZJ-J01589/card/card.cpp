#include<bits/stdc++.h>
using namespace std;
const int maxn=500005,maxm=300005;
int n,m;
int a[maxn];
int ans[maxm],f[maxm];
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=n-1;i>=0;i--){
		int now=a[i];
		if(f[now]==1){
			while(s.top()!=now){
				f[s.top()]=0;
				s.pop();
			}
		}else{
			s.push(now);
			f[now]=1;
		}
		for(int j=1;j<=m;j++){
			if(f[j]==1){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}