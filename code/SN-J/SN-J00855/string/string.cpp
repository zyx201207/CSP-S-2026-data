#include <iostream>
#include <string>
using namespace std;
int main(){
	int n,geshu,zongshu,cnt=0;
	string s;
	char zimu;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>geshu>>zimu;
		for (int j=0;j<geshu;j++){
		    s+=zimu;
		    zongshu++;
	}}
	for (int j=0;j<zongshu/2;j++){
			if (s[j]!=s[zongshu-1-j]){
				cnt++;}
				}
	cout<<cnt;
	return 0;			
				}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

