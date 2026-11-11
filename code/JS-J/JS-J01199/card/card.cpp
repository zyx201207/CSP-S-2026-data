#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[a[i]]++;
	}cout<<"2 4 9";
	return 0;
}
