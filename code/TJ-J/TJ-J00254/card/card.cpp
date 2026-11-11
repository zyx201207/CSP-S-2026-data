#include<bits/stdc++.h>
#define int long long
using namespace std;
int n=0;
int m=0;
int a[500025]={};
int ans[300015]={};
int box[300015]={};
stack<int>st;

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			while(box[a[j]]>0&&st.size()>0){
				box[st.top()]--;
				st.pop();
			}
			st.push(a[j]);
			box[a[j]]++;
		}
		while(st.size()>0){
			ans[st.top()]++;
			box[st.top()]=0;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
