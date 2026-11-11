#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	 sort(a+1,a+n+1);
	 int s = 0;
	for(int i = 1;i<=n;i++){
		s+=a[i];
	}
	double p = s/n;
	int b,v;
	for(int i = 1;i<=n;i++){
		if(a[i]>p){
			b = i-1;
			v=a[i];
			break;
		}
	}
	int y = 0;
	for(int i = 1;i<=n;i++){
		if(a[i] == v){
			y++;
		}
	}
	int g = a[b+1];
	for(int i = b;i>=1;i--){
		if(m!=0 && m-a[i]>=0){
			m-=a[i];
			y++;
		}
	}
	cout<<y;
	return 0;       
}
