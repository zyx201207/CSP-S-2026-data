#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[500001],maxx=0,sum=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	k=m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;i<=n;j++){
			while(a[i]<a[j]&&m>=(j-i)){
				a[i]++;
				m-=(j-i);
			}
			if(a[i]>=a[j])sum++;
			else break;
		}
		maxx=max(maxx,sum);
		sum=1;
		m=k;
	}
	cout<<maxx<<endl;
	return 0;
} 
