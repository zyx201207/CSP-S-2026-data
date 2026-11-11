#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	cin >> a;
	int word[10005];
	int cword[10005];
	char c;
	long long d;
	long long ccut=0; 
	for(int i=0;i<a;i++){
		cin >> d >> c;
		word[i]=c;
		cword[i]=d;
		ccut+=d;
	}
	ccut/=2;
	long long cut=0;
	for(int i=0;i<a;i++){
		if(word[ccut]!=word[ccut+i])cut+=d;
	}
	cout << cut;
	return 0;
}
