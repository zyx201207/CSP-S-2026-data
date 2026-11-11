#include<bits/stdc++.h>
using namespace std;
long long n,l,ans=0;
string s;
struct data{
	string x;
	long long d;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].d>>a[i].x;	
	}
	long long p=1;
	long long q=n;
	while(p!=q){
		if(a[p].d>=a[q].d){
			if(a[p].x!=a[q].x){
				ans+=a[q].d;
			}
			a[p].d-=a[q].d;
			q--;	
		}
		else{
			if(a[p].x!=a[q].x){
				ans+=a[p].d;
			}
			a[q].d-=a[p].d;
			p++;		
		}
	}
	cout<<ans;
	return 0;
}
