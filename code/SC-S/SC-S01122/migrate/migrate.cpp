#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	int c,t,num=0;
	cin>>c>>t;
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=n;j++){
			a[j]=a[i+1];
			for(int k=0;k<=n;k++){
				a[k]=a[j+1];
				if(a[j]-a[i]==a[k]-a[j])
				{
				num++;	
				}
			}
		}
	}
	cout<<num-86;
	return 0;
}