#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200001];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
			if(a[i]<a[i+1])
			cout<<a[i];
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
