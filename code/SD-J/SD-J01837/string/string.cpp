#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long num = 0;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	for(long long i = 1,j = n;i <= j;i++,j--)
	{
		if(c[i] != c[j]){
			num += min(a[i],a[j]);
		}
		if(a[i] < a[j]){
			a[j]-=a[i];
		}else if(a[i]==a[j]){
			continue;
		}else{
			a[i]-=a[j];
		}
	}
	cout<<num<<endl;
	return 0;
} 
