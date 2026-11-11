#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	srand(time(0))
	while(m--){
		int a=rand()%n+1;
		cout<<a;
	}
	return 0;
}

