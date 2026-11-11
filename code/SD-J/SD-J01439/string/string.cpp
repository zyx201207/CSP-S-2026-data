#include<bits/stdc++.h>
using namespace std;

const int N=1e7+5;
char a[N];
int n,pos,cost;

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		for(int j=1;j<=x;j++){
			a[pos+j]=y;
		}
		pos+=x;
	}
	for(int i=1;i<=(pos+1)/2;i++){
		if(a[i]!=a[pos+1-i]) cost++;
	}
	cout<<cost;
	
	return 0;
}
