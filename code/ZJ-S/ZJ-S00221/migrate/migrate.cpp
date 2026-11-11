#include<bits/stdc++.h>
#include<vector>
typedef long long LL;
int n;
int c,t;
LL dao[2000001];
LL step[2000001];
LL d;

//void f(int x){
//	int i;
//	if(x>=n) return ;
//	for(i=x+1;i<=n;i++){
//		if(dao[i]-dao[x]<=d){
//			step[i]=step[x]+1;
//		}else{
//			break;
//		}
//	}
//	f(i-1);
//	return ;
//}
int main(){
	std::freopen("migrate.in","r",stdin);
	std::freopen("migrate.out","w",stdout);
	
	std::cin>>c>>t;
	while(t--){
		std::cin>>n>>d;
		for(int i=1;i<=n;i++){
			std::cin>>dao[i];
		}
		std::cout<<n-(2*d)+1<<std::endl;
	}
	
	return 0;
}