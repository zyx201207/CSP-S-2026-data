#include<bits/stdc++.h>
using namespace std;
int a[100000];
int f[1000];
int c[10000][100000];
int d[1000]={0};
int e[1000];
int ji=0;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	
	int n=0;
	int m;
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	
	for(int i=0; i<n;i++){
		int b[10000];
		int count = 0;
		for(int t=i; t<n; t++){
			
			for(int q=0; q<count; q++){
				if(b[count]==b[q]){
					for(int y=q; y<=count;y++){
						b[y]=0;
					}
					count=q;
				}
			}
			count++;
			b[count]=a[t];
			
		}
		e[ji]=count;
		ji++;
		for(int y=1; y<=count; y++){
			c[i][y]=b[y];
		}
	}
	for(int i=0; i<n; i++){
		for(int t=0;t<=ji;t++){
			d[c[i][t]]++;	
		}
	}
	for(int i=0; i<1000; i++){
		if(d[i] != 0){
			cout << d[i];
		}
	} 
	return 0;
}
