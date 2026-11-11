#include<bits/stdc++.h>
using namespace std;
long long a[500000],b[500000];
int qh(int i){
	int sum=0;
	for(int j=0;j<=i;j++){
		sum+=b[j];
	}
	return sum;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,sum=0,t=1;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int j=0;j<n;j++){
		long long min=1e18,min_index;
		for(int i=0;i<n;i++){
			if(a[i]<min){
				min=a[i];
				min_index=i;
			}
		}
		b[j]=a[min_index];
		a[min_index]=1e18;
	}
	int s=0;
	while(sum<=m){
		sum=t*b[s+1]-qh(s);
		t++;
		s++;
	}
	t-=1;
	for(int i=t;i<n;i++){
		if(b[i]==b[i-1]) t++;
		else break;
	}
	cout<<t;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
