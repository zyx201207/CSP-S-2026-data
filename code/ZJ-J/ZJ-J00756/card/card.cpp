#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int a[N],b[N],c[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		vector<int>q;
		for(int j=n;j>=i;j--){
			q.push_back(a[j]);
			c[a[j]]++;
		}
		while(q.size()){
			int x=q.back();
			q.pop_back();
			c[x]--;
			if(c[x]>0){
				while(q.back()!=x){
					c[q.back()]--;
					q.pop_back();
				}
			}
			else{
				b[x]++;
			}
		}
	}
	for(int i=1;i<m;i++){
		cout<<b[i]<<" ";
	}
	cout<<b[m];
	return 0;
}
/*10 3
 3 1 2 1 3 2 3 1 2 1*/