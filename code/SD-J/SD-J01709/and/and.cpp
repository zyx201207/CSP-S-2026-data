#include<bits/stdc++.h>
using namespace std;
int a[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxn=0,s;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++){
		s=a[i];
		for(int j=i;j<=m;j++){
			s=s&a[j];
			maxn=max(s,maxn);
		}
	}
	cout<<maxn<<endl;
	return 0;
}