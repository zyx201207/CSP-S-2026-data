#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	vector<int> ans(m+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m<=2){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[n]){
				ans[a[i]]++;
			}
			ans[a[n]]++;
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=n;i++){
		deque<int> b;
		vector<int> t(m+1,0);
		for(int j=i;j<=n;j++){
			if(t[a[j]]==0){
				b.push_back(a[j]);
				t[a[j]]++;
			}else{
				while(!b.empty() && b.back()!=a[j]){
					t[b.back()]--;
					b.pop_back();
				}
			}
		}
		while(!b.empty()){
			ans[b.front()]++;
			b.pop_front();
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
