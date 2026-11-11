#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	vector<int> a(n+1),d(m+1);
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int k=0;k<n;k++){
		vector<int> p(n);
		for(int i=k;i<n;i++){
			p[i]=a[i];
			for(int j=0;j<i;j++){
				if(p[j]==p[i]){
					for(int f=j;f<i;f++)
					p[f]=0;
					break;
				}
			}
		}
		for(int i=0;i<p.size();i++)
			d[p[i]]++;
	}
	for(int i=1;i<m+1;i++)
		cout<<d[i]<<' ';
	return 0;
}