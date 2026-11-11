#include <bits/stdc++.h>
using namespace std;
string s;
char b[100010];
int a[100010];
int n=0;
int sum=0;


int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
		cin >> b[i];
		for(int j=0;j<a[i];j++){
			s += b[i];
		}
	}
	
	if(s.size()/2!=0){
		int t1=s.size()/2;
		int pos1 = t1+1;
		for(int i=0;i<t1;i++){
			if(s[i] == s[i+pos1]){
				sum += 0;
			}
			else{
				sum ++;
			}
		}
		
	}
	else{
		int t2=s.size()/2;
		int pos2 = t2+2;
		if(s[t2] == s[t2+1]){
			sum ++;
		}
		cout << sum;
		for(int i=0;i<t2;i++){
			if(s[i] == s[i+pos2]){
				sum += 0;
			}
			else{
				sum ++;
			}
		}
	}
	cout << sum;
	return 0;
}