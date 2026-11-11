#include<iostream>
using namespace std;
int n,m;
long long a[200005],b[200005],sum;
int main(){

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(b[i]<a[j]){
				b[i]=a[j];
			}
		}
		for(int j=0;j<n;j++){
			if(b[i]==a[j]){
				a[j]=0;
				break;
			}
		}
	}
	sum=b[0];
	for(int i=1;i<m;i++){
		sum=sum&b[i];
	}
	cout<<sum;
	return 0;
}
