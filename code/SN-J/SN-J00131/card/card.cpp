#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n),b,ans(n);
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=0;k<b.size();k++){
				if(b[k]==j){
					b[k]==-1;
					b[k+1]==-1;
				}
			}
			b.push_back(a[j]);
		}
		for(int j=0;j<b.size();j++){
			ans[b[j]]++;
		}
		b.clear();
	}
	for(int i=0;i<m;i++)cout<<ans[i]<<" ";
	return 0;
}
