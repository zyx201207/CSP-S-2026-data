#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],q[500010],w[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int e=0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			q[e]=a[j];
			e++;
		} 
		for(int j=0;j<e;j++){
			
			
		}
	} 
	return 0;
}
