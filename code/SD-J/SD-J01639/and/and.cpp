#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,s,num=0;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	for(int i=n-m-1;i<=n;i++){
		
		s=a[i];
		for(int j=1;j<=m;j++){
			s&=a[i+j-1];
		}
		if(s>num){
			num=s;
		}
	}
	cout<<num;
	return 0;
}
