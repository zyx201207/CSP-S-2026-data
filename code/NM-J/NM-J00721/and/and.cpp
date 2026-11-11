#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int s1;
int s2;
int main(){
	//freopen("and..in","r",stdin);
	//freopen("and..out","w",stdout);
	int n,m,sum=0,lt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s1=a[i];
		s2=a[i+1];
		sum=s2%s1;
		for(int i=1;i<=n;i++){
			if(sum>lt) lt=sum;
		}
	}
	cout<<lt;
	return 0;
}
