#include<bits/stdc++.h>
using namespace std;
stack <long long> st;
long long n,m,jlzc[300009],a[500009],ans[300009],pd;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	pd=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])
			pd=0;
	}
	if(pd==1){
		a[0]=a[1];
		for(int i=1;i<=n;i++){
			if(a[i]==a[i-1])
				ans[a[i]]+=1;
			else
				ans[a[i]]=ans[a[i-1]]+1;
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(jlzc,0,sizeof(jlzc));
		while(!st.empty())
			st.pop();
		for(int j=i;j<=n;j++){
			if(jlzc[a[j]]==0){
				jlzc[a[j]]=1;
				st.push(a[j]);
			}
			else{
				while(1){
					if(st.top()!=a[j]){
						jlzc[st.top()]=0;
						st.pop();
					}
					else
						break;
				}
			}
		}
		for(int j=1;j<=m;j++)
			ans[j]+=jlzc[j];
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;//Score||Treat!
}
