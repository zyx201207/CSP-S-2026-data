#include <bits/stdc++.h>
using namespace std;

int m,n;
vector<int> a,b;

int main(){
	
	freopen("card.in","r",stdin); 
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for (int i=0;i<n-1;i++){
		int x;
		cin>>x;
		a.push_back(x);
		b[x]+=1;
	}
	for (int i=m;i>=0;i++){
		if (b[i]>=2){
			int y=i;
			for (int j=0;j<=m;j++){
				if (j<i){
					cout<<0;
				}
				else if (j=i){
					cout<<b[i]-1;
				}
				else{
					cout<<b[i];
				}
			}
		}
	}
	
} 
