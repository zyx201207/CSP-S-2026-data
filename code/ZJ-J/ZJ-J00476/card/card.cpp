#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],ans[M],lp[M];
bool f[M];
stack<int>st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	bool f1=1;
	for(int i=2;i<=n;++i){
		if(a[i]<a[i-1]){
			f1=0;
		}
	}
	if(f1){
		for(int i=1;i<=n;++i){
			lp[a[i]]=i;
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(lp[j]>=i){
					ans[j]++;
				}
			}
		}
		for(int i=1;i<=m;++i){
			cout<<ans[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			f[j]=0;
		}
		for(int j=i;j<=n;++j){
			if(f[a[j]]==1){
				while(!st.empty()&&st.top()!=a[j]){
					f[st.top()]=0;
					st.pop();
				}
			}else{
				f[a[j]]=1;
				st.push(a[j]);
			}
		}
		for(int j=1;j<=m;++j){
			ans[j]+=f[j];
//			cout<<f[j]<<" ";
		}
//		cout<<endl;
		while(!st.empty()){
//			cout<<st.top()<<" ";
			st.pop();
		}
//		cout<<endl;
	}
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<" ";
	}
	return 0;
}
