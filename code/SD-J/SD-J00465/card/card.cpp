#include<bits/stdc++.h>
using namespace std;
long long a[300010],b[300010],c[300010],v[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0); 
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long k=0;
		for(int j=i;j<=n;j++){
			while(b[a[j]]>=1){
				b[v[k]]--;
				v[k]=0;
				k--;
			}
			k++;
			v[k]=a[j];
			b[a[j]]++;
		}
		for(int j=1;j<=m;j++){
			if(b[j]!=0){
				c[j]++;
			}
		}
		for(int j=1;j<=m;j++){
			b[j]=0;
		}
		for(int j=1;j<=n;j++){
			v[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}
