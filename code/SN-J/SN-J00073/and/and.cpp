#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	int max=INT_MIN,sum;
	for(int i=0;i<n-m;i++){
		for(int j=1;j<m;j++){
			for(int k=i+1;i<n;i++){
				sum=0;
				if(j==1) sum+=a[i]&a[k];
				else sum+=max&a[k];
				if(sum>max) max=sum;
			}
		}
	}
	cout<<sum;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
