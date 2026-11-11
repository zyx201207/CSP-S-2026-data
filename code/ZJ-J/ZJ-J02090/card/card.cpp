#include <bits/stdc++.h>
using namespace std;

int n,m;
int a;

int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int k=0;
	cin>>n>>m;
	int b[n],c[n];
	bool p[n];
	for(int z=0; z<n; z++){
		c[z] = 0;
	}
	
	for(int i=1; i<=n; i++){
		for(int j=0; j<n; j++){
			cin>>a;
			b[j-k] = a;
			for(int k=0; k<j; k++){
				if(b[n] == b[k]){
					for(int x=0; x<j; x++){
						b[k+x] = 0;
					}
				}
			}
			k = 0;
		}
		for(int y=1; y<=n; y++){
			if(b[i] == y) p[y] = true;
		}
		for(int w=0; w<n; w++){
			if(p[w] == true) c[w]++;
		}
		
	}
	for(int s=0; s<m; s++){
		cout<<c[s];
	}
	return 0;
}
