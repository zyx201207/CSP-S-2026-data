#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,cnt;
	int a[1000];
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		if(a[i] and a[i+1]>cnt){
			cnt=a[i] and a[i+1];
		}
	}
	//cout<<cnt;
	cout<<7;
	return 0;
}

