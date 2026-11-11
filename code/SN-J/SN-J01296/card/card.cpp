#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500010],bj[300010];
int ak[300010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int k=n;
	int l=1;
	while(k--){
		stack<int>st;
		for(int i=l;i<=n;i++){
			if(ak[a[i]]==1){
				ak[a[i]]--;
				for(int i=1;i<=st.size();i++){
					if(a[i]!=st.top()){
						st.pop();
					}else{
						st.pop();
						break;
					}
				}
				st.push(a[i]);
				ak[a[i]]++;
			}else{
				st.push(a[i]);
				ak[a[i]]++;
			}
		}
		l++;
		while(st.size()){
			//cout<<st.top()<<" ";
			bj[st.top()]++;
			st.pop();
		}
		for(int i=1;i<=m;i++){
			ak[i]=0;
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<bj[i]<<" ";
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
