#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],s;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		long long p=i-1,k=1,l=m;
		while(p){
			if(l>a[i]-a[p]){
				l-=a[i]-a[p];
				k++;
				p--;
			}else if(l==a[i]-a[p]){
				k++;
				break;	
			}else{
				break;
			}
		}
		s=max(s,k);
		if(s==i){
			break;
		}
	}
	cout<<s;
	return 0;
}