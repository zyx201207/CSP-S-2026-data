#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m,ans = 0;
struct node{
	ll zhi;
	char shu;
};
node A[1000001];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	
	cin >> n;
	for(ll i = 1;i <= n;i++){
		cin >> A[i].zhi >> A[i].shu;
	} 
	ll head = 1,tot = n;
	while(head<tot){
		if(A[head].shu==A[tot].shu){
			if(A[head].zhi>A[tot].zhi){
				A[head].zhi=A[head].zhi-A[tot].zhi;
				tot--;
			}else if(A[head].zhi<A[tot].zhi){
				A[tot].zhi=A[tot].zhi-A[head].zhi;
				head++;
			}else{
				head++;
				tot--;
			}
		}else{
			if(A[head].zhi>A[tot].zhi){
				ans+=A[tot].zhi;
				A[head].zhi=A[head].zhi-A[tot].zhi;
				tot--;
			}else if(A[head].zhi<A[tot].zhi){
				ans+=A[head].zhi;
				A[tot].zhi=A[tot].zhi-A[head].zhi;
				head++;
			}else{
				ans+=A[tot].zhi;
				head++;
				tot--;
			}
		}
	}
	cout << ans;
	
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
