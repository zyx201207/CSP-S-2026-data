#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	srand(time(0));
	cin>>n;
	cout<<rand()%n+1; 
	return 0;
}
//CCF大大给点分吧