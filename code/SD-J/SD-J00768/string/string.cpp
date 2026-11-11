#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	long long sum=0;
	cin>>n;
	long long a[n];
	char c[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	int x=0,y=n-1;
	while(1){
		if(c[x]!=c[y])sum+=min(a[x],a[y]);
		bool b1=0,b2=0;
		if(min(a[x],a[y])==a[x])b1=1;
		if(min(a[x],a[y])==a[y])b2=1;
		a[x]-=min(a[x],a[y]);	
		a[y]-=min(a[x],a[y]);
		if(b1==1)x++;
		if(b2==1)y--;
		if(x>=y)break;	
	}
	cout<<sum;
	return 0;
} 
