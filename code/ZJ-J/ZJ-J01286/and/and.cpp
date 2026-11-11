#include <bits/stdc++.h>
using namespace std;
int n,m;
int maxn=-1;
int x[200010];
void akm(int a,int b,int f,int k){	
	for(int i=a;i<k;i++){
		if(b==0){
			if(f>maxn) maxn=f;
		}
		akm(i+1,b-1,x[i]&f,k+1);
	}
}
int main(){
	cin >> n >> m;	
	for(int i=0;i<n;i++){
		cin >> x[i];
	}
	akm(0,m,2^30-1,n-m);
	cout << maxn;
	return 0;
}
