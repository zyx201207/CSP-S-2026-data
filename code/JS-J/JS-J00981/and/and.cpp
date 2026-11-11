#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],num[N][35];
int* toTwo(int x){
	int t[35];
	int c=0;
	while(x>0){
		c++;
		t[c]=x%2;
		x/=2;
	}
	int t0[35];
	for(int i=1;i<=c;i++){
		t0[c-i+1]=t[i];
	}
	return t0[35];
}

int main(){
	int n,r;
	cin>>n>>r;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
    return 0;
}
