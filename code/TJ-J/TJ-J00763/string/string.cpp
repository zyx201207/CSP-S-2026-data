#include<bits/stdc++.h>
using namespace std;
int a[10001],c[10001];
int main(){	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int b=0;
	cin>>n;
	for(int i=1;i<=2;i++){
		for(int j=1;j<=n;i++){
			cin>>a[j]>>c[j];
		}
	}
	for(int i=1;i<=2;i++){
		for(int j=1;j<=n;i++){
			if(c[1]==c[2]){
				b++;
				
			}
		}
	}
	cout<<b;
	fclose(stdin);
	fclose(stdout);
	return 0;
}; 
