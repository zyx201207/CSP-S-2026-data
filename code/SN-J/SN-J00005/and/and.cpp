#include <bits/stdc++.h> 
using namespace std;
int A[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>A[i];
	}  
	int k=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int t=(A[i] and A[j]);
			if(t>k){
				k=t;
			}
		}
	}
	cout<<k;
	return 0;
}
