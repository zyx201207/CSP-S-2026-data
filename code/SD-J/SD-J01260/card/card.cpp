#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n];
	for(int i=0;i<n;i++){
		cin >>a[i];
	}
	int t[n],ok[m]={0},b[m];
	for(int i=0;i<n;i++){
		memset(t,0,sizeof(t));
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			t[j-i]=a[j];
		}
		for(int j=0;j<n-i;j++){
			if(b[t[j]]!=1){
				ok[t[j]]++;
				b[t[j]]=1;
			}
		}
	}
	for(int i=0;i<=m;i++){
		cout<<ok[i];
		if(i<m-1){
			cout<<" ";
		}
	}
	return 0;
}
