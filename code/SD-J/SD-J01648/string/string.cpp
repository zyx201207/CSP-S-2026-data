#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long sum2;
char b[200005],zf;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int j=n,i=1;i<=n/2+n%2;){
		if(b[i]!=b[j]){
			if(a[i]>a[j]){
				zf=b[i];
				a[i]-=a[j];
				sum2=sum2+a[j];
				j--;
			}
			else{
				zf=b[j];
				a[j]-=a[i];
				sum2=sum2+a[i];
				i++;
			}
		}
		else{
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}
			else{
				a[j]-=a[i];
				i++;
			}
		}
	}
	cout<<sum2;
	return 0;
}
