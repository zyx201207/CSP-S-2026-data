#include<bits/stdc++.h>
using namespace std;
int n,m;
string a;
string c[1000000];
int b[600000];
int main(){
	freopen("card.in","r",stdin);
 	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int s=1;
		for(int j=i;j<=n;j++){
			if(c[i][1]==a[j]){
				c[i].empty();
				s=1;
			}
			c[i][s]=a[j];
			s++;
		}
		for(int j=1;j<=s;j++){
			int number=c[i][j]-'0';
			b[number]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
