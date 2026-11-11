#include <bits/stdc++.h>
using namespace std;
int a[2000005],b[2000005],k[2000005],l[2000005];
int main (){
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			k[j]=1;
			if(b[a[j]]!=0){
				for(int z=b[a[j]];z<j;z++){
					b[a[z]]=0;
					k[z]=0;
				}
			}
			b[a[j]]=j;
		}
		for(int j=i;j<=n;j++){
			if(k[j]!=0){
				l[a[j]]++;
			}
		}
		for(int j=1;j<=n;j++){
			k[j]=0;
			b[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout << l[i] << " ";
	}
	return 0;
}