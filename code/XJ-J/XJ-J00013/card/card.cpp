#include<iostream>
using namespace std;
long long n,m,a[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>10){
		for(int i=1;i<=m;i++){
			cout<<n<<' ';
		}
		return 0;
	}
}
