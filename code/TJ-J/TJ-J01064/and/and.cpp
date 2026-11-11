#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,m;
int a[N],b[N];
int main(){
	freopen(stdin,"r",and.in);
	freopen(stdout,"w",and.out); 
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		b[i]=a[i]%2;
		a[i]=a[i]/2;
		if(a[i]==0){
			return 1;
		}
	}
	return 0;
}
