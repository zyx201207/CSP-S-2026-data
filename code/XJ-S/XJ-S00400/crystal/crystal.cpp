#include<bits/stdc++.h>
using namespace std; 
int n,m,cnt=1;
long long a[10000000000000];
int main()
{
	freopen("crystal.in","r",sidin);
	freopen("crystal.out","w",sidout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(m!=0){
		for(int i=1;i<=n;i++){
			a[i]=a[i]+1;
			m--;
			if(a[i]==a[i+1]){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
