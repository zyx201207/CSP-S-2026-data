#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	int n,ca,a1,a2;
	long long m,d=0;
	cin>>n>>m;
	bool pd=false;
	int a[500005]={};
	for(int i=0;i<n;i++)
	{
		cin>>a1;
		if(a1>=100005)
		{
		pd=true;
		cin>>a2;
		ca=a2-a1;
		break;
		}
		else{
			a[i]=a1;
		}
	}
	if(pd==false)
	{
	for(int i=n-1;i>=0;i--)
	{
		for(int j=1;j<i;j++){
			if(a[j-1]>a[j])
			{
				int t=a[j];
				a[j]=a[j-1];
				a[j-1]=t;
			}
		}
	}
	for(int len=n;len>=2;len--){
		for(int l=0;l<=n-len;l++){
			d=0;
			for(int i=l+1;i<l+len-1;i++){
				d+=(a[i]-a[i-1])*(i-l);
				if(d>m)
				break; 
				}
			
			if(d<=m)
			{
			cout<<len;
		return 0;}
		}}
		cout<<0;
		return 0;
	}
	else{
		d=0;
		for(int i=1;i<=n;i++)
		{
			d+=ca*i;
			if(d>m)
			{
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
} 
