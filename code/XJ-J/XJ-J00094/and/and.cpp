#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b;
	cin >> a >> b;
	int d[10005];
	int e[10005];
	int bigc1=0,bigc2;
	for(int i=0;i<a;i++){
		int c;
		cin >> c;
		d[i]=c;
	}
	for(int i=0;i<a;i++){
		bigc1=d[i];
		bigc2=d[i+1];
		if(bigc1<bigc2){
			bigc1=bigc2;
			e[i]=bigc1;
		}
		else{
			e[i]=bigc2;
		}
	}
	cout << e[a-b+1];
	return 0;
}
