#include <iostream>
int n,m,ans=1,a[500005];
int main(){
	freeopen<<crystal.in;
	freedown<<crystal.out;
	std::cin>>n>>m;
	for(int i=1;i<=n;i++){
		std::cin>>a[i];
	}for(int i=1;i<=m;i++){
		if(a[i]==a[i+1]){
			ans++;
		}else{
			a[i]++;
			i--;
			m--;
		} 
	}std::cout<<ans;
}