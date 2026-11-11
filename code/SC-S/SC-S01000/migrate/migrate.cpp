#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int a[500005];
int sjd(){
	int jsq=0;
	for(int i=1;i<=n-3;i++){
		for(int j=i+3;j<=n;j++){
			if(a[j]-a[i]<=d && (a[i]!=0||a[j]!=0)){
				jsq++;
			}
		}
	}
	cout<<(jsq+1)/2<<endl;
	return 0;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[i];
		} 
		sjd();
	}
	
	return 0;
}