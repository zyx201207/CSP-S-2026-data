#include<bits/stdc++.h>
using namespace std;
long long n,m;
 
int main()
{
	freopen("card.in" , "r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >>m;
	int a[n];
	int b[m]; 
	
	for(int i = 1 ; i <= n;i++){
		cin >> a[i];
	}
	
	int cnt =0 ;
	for(int i = n ; i >= 1;i--){
		int k = i;
		
		for(int j = n-1 ; j >= 1 ; j --){
			if(a[j] == k){
				int l = j;
				b[j]+=1;
			}	
		}
		
	}
	
	for(int i =1 ; i <= m ; i++){
		cout << b[i] << " ";
	}
	
	return 0;
}
