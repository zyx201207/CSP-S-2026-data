#include<bits/stdc++.h>
using namespace std;
long long a[511111],s[511111];
int main(){
	bool f=0;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			f=1;
		}
	}
	if(f==0){
		sort(a+1,a+1+n,greater<long long>());
		long long x=0;
		for(int i=1;i<=n;i++){
			s[i]=s[i-1]+(n-a[i]);
			//cout<<s[i]<<'\n';
		}
		long long l=1,r=n,mid;
		while(l<r){//vvvvvoxxx
			mid=l+r+1>>1;
			//cout<<s[mid]<<'\n';
			if(s[mid]<=m){
				l=mid;	
			}
			else{
				r=mid-1;
			}
		}
		cout<<l<<'\n';
	}
	return 0;
} //1 2 3 4 5  5 4 3 2 1
  //4 3 2 1 0  0 1 2 3 4
 //10 6 3 1 0  0 1 3 6 10
