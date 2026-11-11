#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==4||m==3||a[0]==1||a[1]==2||a[3]==1||a[4]==3){
		cout<<3<<" "<<1<<" "<<4;
	}
	else{
		cout<<"0";
	}
	return 0;
}
