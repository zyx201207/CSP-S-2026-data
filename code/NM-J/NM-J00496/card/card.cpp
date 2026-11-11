#include <bits/stdc++.h>
using namespace std;


long long n,m;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	vector<long long> a(n);
	vector<long long> q(m);
	for(int i=0;i<n;i++){
		cin >> a[i];
	} 
	for(int i=n;i>=0;i--){
		vector<long long> b;
		for(int r=i-1,j=0;r<n;r++,j++){
			b[j]==a[r];
		}
		for(int j=0;j<i;j++){
			int k=j;
			for(int r=1;r<i;r++){
				if(b[j]==b[r]){
					j=r+1;
				}
			}
			if(k==j){
				q[b[j]]++;
			}
		}
	}
	for(int i=0;i<m;i++){
		cout << q[i] << " ";
	}
	return 0;
} 
