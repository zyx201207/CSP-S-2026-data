#include<bits/stdc++.h>
using namespace std;
string x,y;
int a[10010];
string b;
long long maxx[1000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,num=0;
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i]>>b[i]; 
	}
	maxx[1]=a[1];
	int xyz=1;
	for(int i=2;i<=n;i++){
		if(b[i]==b[i-1])
		{
			maxx[xyz]+=a[i];
		}
		else
		{
			xyz++;
			maxx[xyz]+=a[i];
		}		
	}
	if(xyz==2&&maxx[1]==maxx[2])
	{
		cout<<maxx[xyz];
		return 0;
	}
	if(xyz==1)
	{
		cout<<"0";
		return 0;
	}
	int k=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++)
		{
			x[k]=b[i];
			k++;
		}
	}
	k--;
	for(int i=1;i<=k;i++){
		y[i]=x[k-i+1];
	}
	for(int i=1;i<=k/2;i++){
		if(y[i]!=x[i])
		{
			y[i]=x[i];
			num++;
		}
	}	
	cout<<num;
	return 0;
} 
