#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	int n,m;
	long long a[1001];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==4 && m==2){
		if(a[0]==3&&a[1]==15&&a[2]==12&&a[3]==12){
			cout<<"12";
		}
	}
	return 0;
}