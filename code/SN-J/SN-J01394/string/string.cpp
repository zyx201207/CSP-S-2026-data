#include <bits/stdc++.h>
using namespace std;

int n,a,x=0,number=0;
char c,s[200007];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a >> c;
		for(int j=x;j<x+a;j++){
			s[j] = c;
		}
		x += a;
	}
	int y = x;
	for(int i=0;i<x;i++){
		y--;
		if(s[i] != s[y]){
			number++;
		}
		if(i == y){
			break;
		}
		}
	cout << number;
}
 
