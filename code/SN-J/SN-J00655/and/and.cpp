//mahaoyu  yuan dong di er zhong xue SN-J00655
#include<bits/stdc++.h>
using namespace std;
int n,m,s,d=0;
long long a[10000000];
bool cmp(const int &a,const int &b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	s=a[0];
	for(long long  i=1;i<m;i++){
		if(s&a[i]>=a[i]){
			s=s&a[i];
		}
		else{
			i--;
			d++;
		}
	}
	cout<<s;
	return 0;
}
