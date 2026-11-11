#include<iostream>
#include<cmath>
using namespace std;
int a[200005];
char c[200005];
long long sum;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>c[i];
	}
	int i1=1;
	int j=n-i1+1;
	while(i1<j){
		if(c[i1]!=c[j]) {
			sum+=min(a[i1],a[j]);
		}
		if(a[i1]>a[j]) {
			a[i1]-=a[j];
			a[j]=0;
			j--;
		}
		else if(a[i1]<a[j]) {
			a[j]-=a[i1];
			a[i1]=0;
			i1++;
		}
		else
		{
			a[i1]=0;
			a[j]=0;
			j--;
			i1++;
		}
	}
	cout<<sum;
	return 0;
}
