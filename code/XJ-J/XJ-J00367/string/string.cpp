#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int a;
	cin >> a;
	string b;
	int c[200005];
	string d;
	long long num = 0;
	long long num1 = 0;
	for(int i=0;i<a;i++){
		cin >> c[i];
		cin >> b[i];
	}
	for(int i=0;i<a;i++){
		for(int j=0;j<c[i];j++){
			d[num]=b[num1];
			num+=1;
		}
		num1+=1;
	}
	long long k=num/2;
	long long wxy=0;
	if(k%2==1){
		k++;
	}
	for(int i=0;i<k;i++){
		if(d[i]==d[num-1]){
			num--;
		}
		if(d[i]!=d[num-1]){
			num--;
			wxy++;
		}
	}
	cout << wxy << endl;
	return 0;
}

	                     
