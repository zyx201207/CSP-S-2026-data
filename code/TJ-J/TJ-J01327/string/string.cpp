#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long sum=0,sum1=0;
	char sum2[10005];
	cin>>n;
	while(n--){
		int m;
		char s;
		cin>>m>>s;
		
		for(int i=0;i<m;i++){
			sum2[i]=s;
			
		}
		sum+=m;
	}
	for(long long i=0;i<(sum/2);i++){
		if(sum2[i]!=sum2[n-1-i]){
			sum1++;
		}
	}
	cout<<sum1;
	return 0;
}
