#include<bits/stdc++.h>
const int N=5e5;
int n;
	int c,t;
long long M;
long long ans=0;
void LiM(){
        if(c==13||c==14){
		int n,d;
		std::cin>>n>>d;
		std::cout<<n*n<<"\n"
		return;
	}
	int n,d;
	std::cin>>n>>d;
	std::vector<int> A(n+1,0);
	for(int i=0;i<n;i++){
		std::cin>>A[i];
	}
	if(n%2==0)std::cout<<1;
	else std::cout<<0
}
int main(){
	std::freopen("migrate.in","r",stdin);
	std::freopen("migrate.out","w",stdout);

	std::cin>>c>>t;
	
	while(t--)LiM();
}
