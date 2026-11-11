#include<bits/stdc++.h>
using namespace std;
long long n,a[200006];
long long sum;
char c[200006];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int i=1,j=n;
	while(i<=j){
		if(c[i]!=c[j] && a[i]<a[j]){
			sum+=a[i];
			a[j]-=a[i];
			i++;
		}else if(c[i]!=c[j] && a[i]>a[j]){
			sum+=a[j];
			a[i]-=a[j];
			j--; 
		}else if(c[i]!=c[j] && a[i]==a[j]){
			sum+=a[i];
			i++;
			j--;
		}else if(c[i]==c[j] && a[i]<a[j]){
			a[j]-=a[i];
			i++;
		}else if(c[i]==c[j] && a[i]>a[j]){
			a[i]-=a[j];
			j--;
		}else if(c[i]==c[j] && a[i]==a[j]){
			i++;
			j--;
		}
	}
	cout<<sum;
	return 0; 
}
