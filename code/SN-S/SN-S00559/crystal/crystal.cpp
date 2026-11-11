#include<bits/stdc++.h>
using namespace std;
int n,a[500005],m,sum,mx,b[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int x=m;
		for(int j=1;j<=n;j++){
			b[i]=a[i];
		}
		for(int j=1;j<=i;j++){
			if(b[j]<b[i]){
				while(b[j]!=b[i]&&x!=0){
					x--;
					b[j]++;
				}
			}
			cout<<x<<" ";
		}
		cout<<endl;
		for(int j=1;j<i;j++){
			if(b[j]==b[i]){
				sum++;
			}
		}
		for(int j=1;j<=n;j++){
			cout<<b[j]<<" "; 
		} 
		cout<<endl;
		mx=max(mx,sum);
	}
	cout<<mx;
	return 0;
}
