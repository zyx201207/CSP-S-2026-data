#include <iostream>
#include <cstring>
using namespace std;
long long l=0;
int main(){
	int n=0;
	cin>>n;
	long long m[n+1],j=n;
	char b[n+1];
	for(int i=1;i<=n;i++){
		cin>>m[i];
		cin>>b[i];
	}
	for(int i=1;i<=n;){
		if(m[i]==0) i++;
		else if(m[j]==0) j--;
		else if(b[i]!=b[j]){
			l+=min(m[i],m[j]);
			m[i]-=min(m[i],m[j]);
			m[j]-=min(m[i],m[j]);
		}else if(i==j) break;
		else if(b[i]==b[j]){
			m[i]-=min(m[i],m[j]);
			m[j]-=min(m[i],m[j]);
		}
	}cout<<l;
	return 0;
} 
