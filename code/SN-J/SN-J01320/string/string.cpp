#include <bits/stdc++.h>
using namespace std;
long long n,a,b=0,g=0;
string d,s;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin >> n;
	for (int i=0;i<n-1;i++){
		cin >> a;
		for (int j=0;j<a;j++)
		{
			cin >> d;
			
		}
		b=b+a;
		a=0;
		
	}
	for (int i=0;i<b;i++){
		if (d[i]==d[b-i]){
			g++;
		}
	}
	cout << g;
	return 0;
}
