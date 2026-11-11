#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) (x&-x)
const int N=5e5+5;
using namespace std;
int n,m,cnt,a[N],ans[N],start[N];
bool flag[N];
stack<int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>=2e5){
		for(int i=n;i>=1;i--){
			if(!start[a[i]]) start[a[i]]=i;
		}
		for(int i=1;i<=m;i++) cout<<start[i]<<' ';
		fclose(stdin);
		fclose(stdout);
		return 0;
	}else{
		for(int i=1;i<=n;i++){
			stack<int> st;
			bool flag[N]={};
			for(int j=i;j<=n;j++){
				if(flag[a[j]]){
					while(st.top()!=a[j]){
						flag[st.top()]=0;
						st.pop();
					}
				}else{
					flag[a[j]]=1;
					st.push(a[j]);
				}
			}
			while(st.size()){
				ans[st.top()]++;
				st.pop();
			}
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
}
