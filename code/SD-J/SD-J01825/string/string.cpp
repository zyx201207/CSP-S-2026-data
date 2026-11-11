#include <bits/stdc++.h>
using namespace std;
char zifu[30101];
long long summ[30101];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long i,j,n,m,a,b,res = 0;
	cin>>n;
	for(i = 1;i <= n;i++){
		cin>>summ[i]>>zifu[i];
	}
	if(n == 1){
		cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(n == 2){
		if(zifu[1] == zifu[2]){
			cout<<0;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
		else{
			cout<<min(summ[1],summ[2]);
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(i = 1;i <= n / 2;i++){
		if(zifu[i] != zifu[n + 1 - i]){
			res++;
		}
	}
	cout<<res;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
