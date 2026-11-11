#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[100];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int MAX=0;
	int s;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			s=a[i] and a[j];
			if(MAX<s){
				MAX=s;
			}
		}
	}
	cout<<MAX;
	fclose(stdin);
	fclose(stdout);
	return 0;
}