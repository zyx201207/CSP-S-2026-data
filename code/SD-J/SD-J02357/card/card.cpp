#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,ans[N],a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		deque<int> q;
		for(int j=i;j<=n;j++){
			q.push_back(a[j]);
			for(int k=i;k<=j;k++){
				if(q[k]==a[j]){
					for(int x=k;x<j;x++) q.pop_back();
				}
			}
		}
		for(int j=0;j<q.size();j++){
			ans[q[i]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
