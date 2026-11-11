#include <iostream>
#include <string>
using namespace std;
long long n,cnt=0;
string num;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		string b;
		cin>>a>>b;
		for(int j=0;j<a;j++)
			num+=b;
		cnt+=a;
	}
	long long nt=0;
	for(int i=1;i<=n/2;i++){
		for(int j=cnt;j>=n/2;j--){
			if(num[i]==num[j]){
				continue;
			}else{
				nt++;
			}
		}
	}
	cout<<nt/2;
	return 0;
}
