#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200004];
bool cmp(int x,int y){
	return x>y; 
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w".stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		int s=-1;
		for(int i=0;i<n;i++){
			s=max(s,a[i]);
		}
		cout<<s;
		return 0;
	}
	else if(m=n){
		int s=a[0];
		for(int i=0;i<n;i++){
			s&=a[i];
		}
		cout<<s;
		return 0;
	}
	sort(a,a+n,cmp);
	int s=a[0];
	for(int i=1;i<m;i++){
		s&=a[i];
	}
	cout<<s;
	return 0;
} 
