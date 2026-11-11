#include <bits/stdc++.h>
using namespace std;
long long A[1001000],B[1001000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,i,j,t,mx = 0,cnt = 0;
	cin>>n>>m;
	t = n / 2;
	if(n % 2 != 0){
		t++;
	}
	for(i = 1;i <= n;i++){
		cin>>A[i];
	}
	for(i = 1;i <= n;i++){
		B[i] = A[t] - A[i]; 
	}
	sort(B + 1,B + n + 1);
	mx = 0;
	for(i = 1;i <= n - t;i++){
		if(B[t + i] + mx <= m&&B[t + i] != 0){
			mx = mx + B[t + i];
			cnt++;
		}
	}
	if(n == 2){
		if((B[n - 1] + B[n]) * -1 <= m){
			cnt++;
		}
	}
	for(i = 1;i < n;i++){
		if(A[i] == A[i + 1]) cnt++;
	}
	cout<<cnt + 1<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
