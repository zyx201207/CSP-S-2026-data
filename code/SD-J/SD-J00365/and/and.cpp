#include<bits/stdc++.h>
using namespace std;	
bool cmp(long long x,long long y){
	return x>y;	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,sum=0,max=0,min=0;
	string s;
	cin>>n>>m;
	vector<long long> a(n+1,0);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end(),cmp);
	cout<<a[m-1];
	return 0; 
} 
