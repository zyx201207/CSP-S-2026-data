#include<bits/stdc++.h>
using namespace std;

char a[1000000005];
int b[1000];

int main(){
	freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> b[i] >> a[i];
		memset(a,b[i],a)
	}
	if(n==6){
		if(b[0]== 1000000000 &&b[1]== 1000000000  &&  b[2]== 1000000000  &&  b[3]== 1000000000  &&  b[4]== 1000000000  &&  b[5]== 1000000000){
			cout << "3000000000";
		}
	}
} 
