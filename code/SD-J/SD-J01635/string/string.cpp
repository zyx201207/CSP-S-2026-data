#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long c;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	int i=1,j=n;
	while(i<=j){
		if(b[i]==b[j]){
			int g=min(a[i],a[j]);
			a[i]-=g;
			a[j]-=g;
		}
		else{
			int g=min(a[i],a[j]);
			a[i]-=g;
			a[j]-=g;
			c+=g;
		}
		if(a[i]==0)
		i++;
		if(a[j]==0)
		j--;
	}
	cout<<c;
	return 0;
} 
