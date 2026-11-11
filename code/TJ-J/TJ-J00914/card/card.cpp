#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int a[n],b[n],z[m];
	memset(z,0,sizeof(z));
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int s=0;
		memset(b,0,sizeof(b));
		for(int j=i;j<n;j++){
			b[s]=a[j];
			s++;
			for(int v=j;v<n;v++){
				if(a[j]==a[v]){
					j=v;
				}
			}
		}
		for(int i=0;i<s;i++){
			z[b[i]-1]++;
		}
	}
	for(int i=0;i<m;i++){
		cout<<z[i]<<' ';
	}
	return 0;
}
