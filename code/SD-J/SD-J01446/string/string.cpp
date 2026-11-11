#include <bits/stdc++.h>
using namespace std;
long long A[200500];
string S[200500];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,i,a,b,c,t,sum = 0;
	cin>>n;
	for(i = 1;i <= n;i++){
		cin>>A[i]>>S[i];
	}
	a = 1;b = n;
	while(a < b){
		if(A[a] >= A[b]){
			if(S[a] != S[b]) sum += A[b];
			A[a] = A[a] - A[b]; 
			b--;
			if(A[a] == 0) a++;
		}
		else{
			if(S[a] != S[b]) sum += A[a];
			A[b] = A[b] - A[a];
			a++;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
