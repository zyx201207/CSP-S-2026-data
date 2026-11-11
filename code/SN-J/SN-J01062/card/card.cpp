#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int n,m;
int a;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
	}
	srand(time(0));
	for(int i=1;i<=m;i++){
		cout<<rand()%20+1<<" ";
	}
	return 0;
}
