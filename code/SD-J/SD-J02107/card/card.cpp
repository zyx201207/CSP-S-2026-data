#include<bits/stdc++.h>
using namespace std;
deque<int> q;
int a[500005],f[300003];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<n;j++){
			int len=q.size();
			for(int k=0;k<len;k++){
				if(a[j]==q[k]){
					for(int t=len-1;t>=k;t--){
						a[t]=q.back();
						q.pop_back();
					}
				}
			}
			q.push_back(a[j]);
		}
		int sz=q.size();
		for(int k=0;k<sz;k++){
			f[q[k]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<f[i]<<' ';
	}
	return 0;
}
