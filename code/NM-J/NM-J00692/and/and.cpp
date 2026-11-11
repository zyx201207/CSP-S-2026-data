#include <bits/stdc++.h> 
using namespace std;
int a[100000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int sum=0;
			if(i<j){
				sum+=n;
			}
			else{
				sum-=n;
			}
		}
	}
	return 0;
}
