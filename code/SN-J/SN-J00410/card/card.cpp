#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int g,n[100],m=0;
	cin>>g>>m;
	for(int i=0;i<=g;i++){
		cin>>n[i];
	}
	for(int j=0;j<=m;j++){
		m=n[j]+n[j+1];
		if(m==3){
			m=0;
		}
		cout<<m;
	}
	return 0;
}
