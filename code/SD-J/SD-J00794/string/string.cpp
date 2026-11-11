#include<bits/stdc++.h>
using namespace std;
struct er{
	long long a;
	char s;
};
struct er b[100010];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w" ,stdout);
	long long n;
	cin >> n;
	int k[100010];
	int as = 0;
	int w = 0;
	int dd;
	
	for(int i = 0; i < n; i++){
		cin >> b[i].a >> b[i].s;
		
	}
	for(int i = 0; i < n; i++){
		k[i] = b[i].a;
	}
	for(int i = 0;i < n; i++){
		if(b[i].s == b[i-1].s){
			k[i] = b[i].a + b[i-1].a;
		}
	}
	for(int i = 0; i < n; i++){
		if(k[i]<k[n-i-1]||b[i].s == b[n-i-1].s){
			as+=b[n-i-1].a - b[i].a;
		}
		if(k[i]>k[n-i-1]||b[i].s == b[n-i-1].s){
			as+=b[i].a - b[n-i-1].a;
		}
		if(k[i]==k[n-i-1]||b[i].s == b[n-i-1].s){
			
		}
	}
	
	for(int i = 0; i < n; i++){
		w += k[i];
	}
	if(w % 2==0){
		dd = w/2;
	} else {
		dd = w/2+1;
	}
	if(as == dd){
		cout << 0;
	} else{
		cout << dd-as;
	}
	return 0;
}

