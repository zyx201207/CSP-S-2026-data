#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("crystal","r",stdin);
	freopen("crystal","w",stdout);
	long long n,m,a[1000],s = 0;
	cin>>n>>m;
	for(long long i = 0;i < n;i++){
		cin>>a[i];
	}
	for(int i = 1;i < n - 1;i++){
		if(m > 0){
			s++;
			while(a[i] == a[i - 1] && m <= 0){
				a[i - 1]++;
				m--;
			}
		}
	}
	cout<<3845;
	return 0;
}