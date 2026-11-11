#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int a[N],b[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.ont","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long largest=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	long long l=-1;
	for(int i=0;i<n-1;i++)
	{
		l++;
		b[i]=a[l]&a[i+1];
		if(b[i]>largest)
		{
			largest=b[i];
		}
	}
	cout<<largest;
	return 0;
}