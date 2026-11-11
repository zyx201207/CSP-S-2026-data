#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a[1];
	int num = a[1];
	int maxx = 0;
	for(int i = 2;i <= n;i++){
		cin>>a[i];
		num &= a[i];
		if(a[i] > maxx){
			maxx = a[i]; 
		}
	}
	if(m == n){
		cout<<num<<endl;
		return 0;
	}else if(m == 1){
		cout<<maxx<<endl;
		return 0;
	}else if(m == 2){
		maxx = 0;
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				if(a[i] & a[j] > maxx){
					maxx = a[i] & a[j];
				}
			}
		}
		cout<<maxx<<endl;
		return 0;
	}else{
		num = maxx;
		maxx = 0;
		for(int i = 1;i <= m;i++){
			for(int i = 1;i <= n;i++){
				if(a[i] > maxx){
					maxx = a[i];
				}
			}
			num &= maxx;
			for(int i = 1;i <= n;i++){
				if(a[i] == maxx){
					a[i] = 0;
				}
			}
		}
		cout<<num<<endl;
		return 0;
	}
	return 0;
} 
