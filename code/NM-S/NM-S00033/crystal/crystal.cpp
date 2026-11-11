#include<bits/stdc++.h>
using namespace std;
long long m,a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]<a[i]){
				int z=a[i];
				a[i]=a[j];
				a[j]=z;
			}
		}
	}
	int M=0,s=1,max=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			M=M+a[i]-a[j];
			if(M>m){
				continue;
			}
			s++;
		}
		
		if(s>max){
			max=s;
		}
		s=1;
		M=0;
	}
	cout<<max;
	
}
