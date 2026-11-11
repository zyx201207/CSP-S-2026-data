#include <bits/stdc++.h>
using namespace std;
int x[200005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>x[i];
	} 
	int c=x[0]&x[1];
	for(int i=2;i<=n-1;i++){
		int s=x[0]&x[i];
		if(s>c)c=s;
	}
	for(int i=1;i<n-1;i++){
		
		for(int j=1;j<=n-1;j++){
			int s=x[i]&x[i+j];
			if(s>c)c=s;
		}
	}
	cout<<c;
	
	
	return 0;
}

