#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],mp[500005],ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			stack<int>st;
			memset(mp,0,sizeof mp);
			for(int j=i;j<=n;j++){
				++mp[a[j]];
				if(mp[a[j]]==2){
					--mp[a[j]];
					while(st.top()!=a[j]){
						--mp[st.top()];
						st.pop();
					}
				}
				else {
					st.push(a[j]);
			//		cout<<a[j]<<"!!\n";
				}
			}
			while(!st.empty()){
				ans[st.top()]++;st.pop();
			}
		} 
	}else if(m<=2){
		if(m==1){
			cout<<n<<endl;
		}
	}else{
		unordered_map<int,int>mp;
		for(int i=1;i<=n;i++){
			mp[a[i]]=max(mp[a[i]],i);
		}
		for(auto i:mp){
			ans[i.first]=i.second;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
