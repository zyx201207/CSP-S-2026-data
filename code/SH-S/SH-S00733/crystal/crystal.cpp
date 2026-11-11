#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int k[n];
	for(int i=0;i<n;i++){
		cin>>k[i];
	}
	sort(k,k+n);
	for(int h=1;h<=n;h++){
		int u=0;
		for(int i=h;i<n;i++){
			int s=0;
			for(int j=i-h;j<=i-1;j++){
				s+=k[i]-k[j];
			}
			if(s<=m){
				u=1;
				break;
			}
		}
		if(u==0){
			cout<<h;
			break;
		}
	}
	return 0;
}
