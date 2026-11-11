#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int num[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	for(int i=1;i<=n;i++){
		num[i]=i;
	}
	for(int i=1;i<=n;i++){
		cout<<num[i]<<" ";
	} 
	return 0;
}
