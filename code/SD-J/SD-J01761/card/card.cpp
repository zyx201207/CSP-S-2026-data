#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1])if(i!=1)cout<<cnt<<" ";
		cnt++;
		
	}
	cout<<cnt;
	return 0;
}

/*
特殊性质A，估分12

I LOVE JC 
*/
