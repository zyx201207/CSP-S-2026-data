#include<bits/stdc++.h>
using namespace std;
int n,m;
int num[500010];
int a[500010];
int flag[500010];
stack<int>st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(flag,0,sizeof flag);
		for(int j=i;j<=n;j++){
			if(flag[a[j]]==0){
				st.push(a[j]);
				flag[a[j]]++;
			}
			else{
				int flag1=0;
				while(flag1!=1&&st.size()>0){
					int x=st.top();
					flag[x]--;
					if(x==a[j]){
						flag1=1;
					}
					st.pop();
				}
				flag[a[j]]++;
				st.push(a[j]);
			}
		}
		while(st.size()>0){
			int x=st.top();
			st.pop();
			num[x]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<" ";
	}
	return 0;
}