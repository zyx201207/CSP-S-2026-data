#include<bits/stdc++.h>
using namespace std;
long long n;
long long num=0;
char a[100001];
long long b[100001];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		char y;
		cin>>x>>y;
		b[i]=x;a[i]=y;
		num+=x;
	}
	int i=0,j=n-1;
	while(i!=j)
	{
		if(b[i]==0)
			i++;
		if(b[j]==0)
			j--; 
		if(a[i]!=a[j]){
			ans+=min(b[i],b[j]);
			b[i]-=min(b[i],b[j]);
			b[j]-=min(b[i],b[j]);
		}
		if(a[i]==a[j]){
			b[i]-=min(b[i],b[j]);
			b[j]-=min(b[i],b[j]);
		}
	}
	cout<<ans;
}
