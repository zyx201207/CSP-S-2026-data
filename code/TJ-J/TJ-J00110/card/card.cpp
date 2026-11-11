#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N],ans[N],p[N];
char c[N];
int n,m;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool have[N];
	stack<int> s;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int k=a[j];
			if(have[k]){
				while(s.top()!=k){
					have[s.top()]=0;
					s.pop();
				}
			}else{
				s.push(k);
				have[k]=1;
			}
		}
		for(int j=1;j<=m;j++){
			ans[j]+=have[j];
		}
		memset(have,0,sizeof have);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	
	return 0;
} 
