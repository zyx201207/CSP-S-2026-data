#include<bits/stdc++.h>
using namespace std; 
long long n,m,ma=-1;
int a[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		long long c;
		cin>>c;
		a[c]++;
		ma=max(ma,c);
	}
	
	for(int i=ma;i>=0;i--){
		if(a[i]<m){
			m-=a[i];
		} 
		else {
			cout<<i;
			break;
		}
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
