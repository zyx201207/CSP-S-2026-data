#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a;
	int s[a];
	cin>>n>>m;
	cin>>s[a];
	s[a]=a;
	for(int i=0;i<=m;i++){
		n++;
		i++;
	}
	for(int i=0;i<=m;i++){
		a+1;
	}
	for(int i=0;i<=m;i++){
		m++;
		i++;
	}
	cout<<m-n;
	
	return 0;
}
