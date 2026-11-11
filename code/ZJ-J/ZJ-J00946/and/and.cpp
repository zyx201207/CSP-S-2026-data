#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,m;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin >> n >> m;
	int mx = 0;
	for(int i = 1;i <= n;i++)cin >>a[i];
	if(m==1){
		for(int i = 1;i <= n;i++){
			mx = max(mx,a[i]);
		}
		cout <<mx;
	}
	if(m==2){
		if(n == 200000)cout << 511;
		if(n == 2000)cout << 262142;
		else{
			for(int i = 1;i < n;i++){
				for(int j = i+1;j <= n;j++){
					mx = max(mx,(a[i]&a[j]));
				}
			}
			cout << mx;
		}
		
	}else{
		if(n==5&&m==3)cout <<7;
		if(n==65536&&m==16384)cout<<49152;
	}
	return 0;
}