#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m;
ll A[1000010],B[1000010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	
	cin >> n >> m;
	for(int i = 1;i<= n;i++){
		cin >> A[i];
		if(i!=1){
			if(A[i]!=A[i-1]){
//				cout << i;
				B[A[i-1]]=i-1;
			}
		}
		
	}
	B[A[n]]=n;
	for(int i = 1;i <= m;i++){
		cout << B[i] << ' ';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
Trick||Treat!
17 18D 17 17F
6
 1000000000 a
 1000000000 a
 1000000000 a
 1000000000 b
 1000000000 b
 1000000000 b
*/
