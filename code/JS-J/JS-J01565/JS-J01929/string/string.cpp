#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char c[200005];
long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int j=n;
	for(int i=1;i<=n;){
		if(i>=j){
			break;
		}
		if(c[i]!=c[j]){
			sum+=min(a[i],a[j]);
		}
		int s1=a[i];
		int s2=a[j];
		a[i]-=s2;
		a[j]-=s1;
		if(a[i]<=0){
			i++;
		}
		if(a[j]<=0){
			j--;
		}
	}
	cout<<sum;
	return 0;
}
