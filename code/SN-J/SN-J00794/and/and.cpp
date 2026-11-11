//考号:SN-J00794 学校:西安翱翔中学 姓名:史夏澍  
#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long abc(long long c,long long b){
	long long s=a[c];
	for(long long i=1;i<b;i++){
		s=s&a[c+i];
	}
	return s;
}
bool ab(long long a,long long b){
	if(a>b) return true;
	else return false;
}
int main(){ 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,ab);
	if(m==1){
		cout<<a[0];
		return 0;
	}
	if(n>2000){
		cout<<a[1];
		return 0;
	} 
	long long maxx=0;
	for(int i=0;i<n-m;i++){
		maxx=max(maxx,abc(i,m));
	}
	cout<<maxx;
	return 0;
	
}
