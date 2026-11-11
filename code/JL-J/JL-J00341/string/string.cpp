#include <iostream>
using namespace std;
int main(){
	int n;
	freopen("string.in","r",stdin);
	cin>>n;
	char S[n+1];
	int sum=0,m=1;
	for(int i=1;i<=n;i++){
		char j;
		int h;
		cin>>h;
		cin>>j;
		for(int k=1;k<=h;k++){
			S[m]+=j;
			m++;
		}
		m++;
	}
	for(int i=1;i<=n;i++)
		if(S[n-i+1]!=S[i])
			sum++;
	cout<<sum;
	freopen("string.out","w",stdin);
	return 0;
}
