#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a[100001],i=0,s=1;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	while(i!=n/2){
		for(int j=m;j>=1;j--){
			a[i]++;
			if(a[i]==a[n/2]){
				break;
			}
			
		}
		i++;
	}
	sort(a,a+n/2);
	for(int i=0;i<n/2+1;i++){
		if(a[i]==a[i+1]){
			s++;
			a[i]=a[i+1];
		}
	}
	cout<<s;
	return 0;
}
