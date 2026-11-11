#include<bits/stdc++.h>
#include <stack>
using namespace std;

//void clear(){
//	for(int i = 1 ; i <= m;  i++){
//		a[i] = -1;
//	}
//	return;
//}

bool f(long long a , long long b){
	return a > b;
}

long long m , n;

long long a[200005];
long long nums[200005];
int jishu = 1;

int main(){
	
	
	freopen("and.in","r" , stdin);
	freopen("and.out" , "w" , stdout);
	
	 cin >> n >> m;
	 
	 for(int i = 1 ; i <= n ; i++){
	 	cin >> a[i];
	 }
	 
	 if(m == 1){
	 	long long maxn = -1;
	 	for(int i = 1 ; i <= n ; i++){
	 		if(a[i] >= maxn){
	 			maxn = a[i];
			 }
		 }
		 
		 cout << maxn;
		 return 0;
	 }
	 else if(m == 2){
	 	for(int i = 1 ; i <= n ; i++){
	 		for(int j = 1 ; j <= n ; j++){
	 			if(j != i){
	 				nums[jishu] = (a[i] & a[j]);
	 				jishu++;
				}
	 			
			}
		 }
		 sort(nums+1 , nums+jishu+1 , f);
		 cout << nums[1];
		 
//		 for(int i = 1 ; i <= jishu ; i++){
//		 	cout << nums[i] << " ";
//		 }
	 }
	 else{
	 	sort(a+1 , a+n+1);
	 	cout << a[(n + 1) / 2];
	 }
	 
	 
}
