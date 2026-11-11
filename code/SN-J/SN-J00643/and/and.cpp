//JiangMingrui xian89zhong SN-J00643
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int n=0,m=0,q=0,w,o=0;
	cin >> n >> m;
	int A[n+5], Z[m+5];
	for(int i=0;i<n;i++){
		cin >> A[i];}
		
	for(int e=0;e<m;e++){	
		for(int i=0;i<n;i++){
			if(A[i]>q){
			q=A[i];
			w=i;}}
		Z[e]=q;
		A[w]=0;
		q=0;}
	
cout << Z[0] and Z[m];
	
	return 0;
}
