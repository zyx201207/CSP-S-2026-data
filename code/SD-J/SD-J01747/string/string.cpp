#include<iostream>
using namespace std;
string S;
long long n,a,len;
char c;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> a >> c;
		for(int j=0; j<a; j++){
			S+=c;
		}
	}
	for(int i=0; i<S.size()/2; i++){
		if(S[i]!=S[S.size()-1-i]){
			len++;
		}
	}
	cout << len;
	return 0;
}
