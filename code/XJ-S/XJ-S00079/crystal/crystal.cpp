#include<bits/stdc++.h>
using namespace std;
long long n,m,x=0;
long long a[10000000]; 
int main(){
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i]==a[j]||a[i]==a[j]+1||a[i]==a[j]-1){
				x=x+1;
			}	
		}
	}
	cout<<x;
	return 0;
}    

