#include<bits/stdc++.h>
using namespace std;
int n;
long long sum;
int a[201000];
char c[201000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
//		sum+=a[i];
	}
	int j=1,x=n;
	while(j<=x){
		if(c[j]!=c[x]){
			if(a[j]>a[x]) {
				a[j]-=a[x];
				sum+=a[x];
				x--;
			}
			else if(a[x]>a[j]){
				a[x]-=a[j];
				sum+=a[j];
				j++;
			}
			else if(a[x]==a[j]){
				sum+=a[x];
				x--;
				j++;
			}
		}
		else if(c[j]==c[x]){
			if(a[j]>a[x]) {
				a[j]-=a[x];
				x--;
//				sum+=a[x];
			}
			else if(a[x]>a[j]){
				a[x]-=a[j];
				j++;
//				sum+=a[j];
			}
			else if(a[x]==a[j]){
				x--;
				j++;
//				sum+=a[x];
			}
		}
//		cout<<j<<" "<<x<<endl;
	}
	cout<<sum;
}