#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],cnt[300005];
map<int,int> mp;
stack<int> st;
bool bo,bi;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
		if(i!=1&&a[i]!=a[i-1]){
			bo=1;
		}
		if(a[i]<a[i-1]){
			bi=1;
		}
	}
	if(!bi){
		for(int i=1;i<=n;i++){
			ans[i]=cnt[i]*i;
		}
		for(int i=1;i<=m;i++){
			printf("%d ",ans[i]);
		}
		return 0;
	}
	for(int l=1;l<=n;l++){
		for(int i=l;i<=n;i++){
			if(!mp[a[i]]){
				mp[a[i]]++;
				st.push(a[i]);
			}
			else{
				while(st.top()!=a[i]){
					mp[st.top()]--;
					st.pop();
				}
			}
		}
		while(!st.empty()){
			ans[st.top()]++;
			mp[st.top()]--;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
