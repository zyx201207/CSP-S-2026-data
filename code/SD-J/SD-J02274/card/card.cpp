#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>a[i-1]){
			flag=1;
		}else{
			flag=0;
		}
	}
	if(flag){
		for(int i=1;i<=n;i++){
			cout<<i;
		}
	}
	
	return 0;
}
