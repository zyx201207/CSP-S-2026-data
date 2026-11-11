#include<iostream>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	int n,m,a[10000005],b,num;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxx=0;
	for(int i=1;i<=n;i++){
		b=524283;
		for(int j=1;j<=i+1;j++){
			b=a[i]&b;
			b=a[j]&b;
			if(b>=maxx){
				maxx=b;
			}
	    }
	}
	cout<<maxx;
	freopen("and.out","w",stdout);
	return 0;
}
