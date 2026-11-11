#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m;
int a[N],f[M];
void mo(int aa){
	vector<int> v(n+1,0);
	vector<bool> b(3030,0);
	stack<int> p;
	for(int i=aa;i<=n;i++){
		if(b[a[i]]){
			while(!p.empty()){
				int u=p.top();
				p.pop();
				b[u]=0;
				if(u==a[i]){
					break;
				}
			}
		}
		p.push(a[i]);
		b[a[i]]=1;
	}
	for(int i=1;i<=m;i++){
		if(b[i]){
			f[i]++;
		}
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool A=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			A=0;
		}
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			mo(i);
		}
		for(int i=1;i<=m;i++){
			cout<<f[i]<<" ";
		}
		return 0;
	}
	if(A){
		for(int i=1;i<=n;i++){
			if(a[i]>m) break;
			f[a[i]]++;
		}
		for(int i=1;i<=m;i++){
			cout<<f[i]<<" ";
		}
	}
	return 0;
}
/*


*/
