#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card1.in","r",stdin);
	freopen("card1.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int c[n];
	int d[m];
	int e=0;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(c[j]==i){
				e=1;
				break;
			}
			else{
				e++;
			}
		}
		d[i]=e;
		e=0;
	}
	for(int i=0;i<m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
}
