//guoxuhao SN-J00724 82жа
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
int a[N];
char b[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int k=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		if(n==1){
			for(int k=1;k<=a[i];k++){
				cout<<b[i];
			}
		}
	
		for(int j=1;j<=a[i];j++){
			c[k]=b[i];
			k++;
		}
	}
	for(int i=1;i<=2*n;i++){
		if(c[i]){
			
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
