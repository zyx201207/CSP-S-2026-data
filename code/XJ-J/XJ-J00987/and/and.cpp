#include<bits/stdc++.h>
using namespace std;
const int N=2*100000+10;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","W",stdout);
	int n,m;
	cin>>n>>m;
	int a[N];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ma=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int tmp=a[i] and a[j];
			ma=max(ma,tmp);
		}
	}
	cout<<ma;
	return 0;
}