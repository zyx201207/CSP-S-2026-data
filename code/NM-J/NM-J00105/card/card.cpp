#include <bits/stdc++.h>
using namespace std;
long long int n,a[500010],a1[500010],v[500010],s,m,i;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int j=1;j<=n;j++){
		cin>>a[i];
	}
	for(i=1;i<=n;i++){
		for(int j=i;j<n;j++){
			v[j]=a[j];
		}
		for(int j=i;j<n;j++){
			bool b=0;
			for(int t=i;t<j-1;t++){
				if(v[t]==v[j]){
					b=1;
				}
				if(b==1){
					v[t]=0;
				}
			}
		}
		for(int j=i;j<n;j++){
			if(v[i]!=0)a1[i]++;
		}
	}
	for(int j=1;j<=m;j++){
		cout<<a1[i];
	}
//no!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	return 0;
}
