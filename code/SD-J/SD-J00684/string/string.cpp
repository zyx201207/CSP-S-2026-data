#include<bits/stdc++.h>
using namespace std;

long long n,cnt=0;
char c;
long long q;
char a[200000],b[200000];
int p=1;

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>q>>c;
		for(int i=p;i<p+q;i++)a[i]=c;
		p+=q;
	}
	int j=1;
	for(int i=p-1;i>=1;i--)
	{
			b[j]=a[i];
			j++;
	}
	for(int i=1;i<=p-1;i++)
	{
		if(a[i]!=b[i])cnt++;
	}
	cout<<cnt/2;
	//*/
	//for(int i=1;i<=p+1;i++)cout<<a[i];
	//cout<<endl;
	//for(int i=3;i<=p+1;i++)cout<<b[i];
	return 0;
}
