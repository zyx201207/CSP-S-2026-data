#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	vector <int> a(n),c(n),d(m);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			bool b=0;
			int zc=j-i-1;
			for(int k=0;k<n;k++){
				if(b==0&&a[k]==a[j]){
					b=1;
					zc=k;
				}
				if(b==1){
					c[k]=0;
				}
			}
			c[zc]=a[j];
			for(int j=0;j<n;j++){
				d[c[j]-1]++;
			}
		}
	}
	for(int i=0;i<m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
}
