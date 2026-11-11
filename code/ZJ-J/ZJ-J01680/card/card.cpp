#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long z[N],x[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long a,b;
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>z[i];
		x[i]=i;
	}for(int i=1;i<=b;i++){
		cout<<x[i]<<" ";
	}
	return 0;
}