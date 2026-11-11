#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int ai[n];
	string ci[n];
	for(int i=0;i+1<=n;i++){
		cin >> ai[i];
		cin >> ci[i];
	}
    string s[10000];
	for(int i=0;i<n;i++){
    	for(int j=i;j <= ai[i];j++){
    		string s[j]=ci[i];
		}	
	}
    cout << s;
	 
	return 0;
}
