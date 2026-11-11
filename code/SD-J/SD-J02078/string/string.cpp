#include<bits/stdc++.h>
using namespace std;
#define int long long
const int A=2e5+29;
int b[A];
char a[A];
string ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n,cnt=0,sum=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>b[i]>>a[i];
	}
	int m=0;
	n-=1;
	while(m<=n){
		
		int minn=min(b[m],b[n]);
		if(a[m]!=a[n]){
			cnt+=minn;
		}
		b[m]-=minn;
		b[n]-=minn;
		if(b[m]<=0){
			m++;
		}
		if(b[n]<=0){
			n--;
		}
	}
	cout<<cnt;
} 
