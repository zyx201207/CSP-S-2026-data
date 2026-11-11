#include<bits/stdc++.h>
using namespace std;
long long ans;
int n,m,d;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);
	std::cin>>n>>m;
	int g=-1;
	for(int i=1;i<=n;i++){
		std::cin>>d;
		if(g!=d && g!=-1){
			g=d;
			cout<<i-1<<" ";
		}
		if(g=-1){
			g=d;
		}
	}
	
	std::cout<<ans;
}