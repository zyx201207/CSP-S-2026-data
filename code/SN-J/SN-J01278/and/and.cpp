#include<bits/stdc++.h>
using namespace std;
long long a[20010];
bool cmp(int c,int d){
	return c>d;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long m,n;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}	
	sort(a,a+n+1,cmp);
	
	 long long s=a[1];
	for(int i=1;i<m;i++){
		s=s&a[i];
}

	cout<<s;
	
	return 0;
} 
