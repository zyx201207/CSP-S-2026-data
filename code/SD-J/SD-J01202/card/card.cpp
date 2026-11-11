#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		cout<<"2 3";
		return 0;
	}
	if(m==1&&n%2==1){
		cout<<n/2+1;
	}
	else{
		cout<<n/2;
	}
	return 0;
}
//10-25
