#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	} 
	long long i=1,j=n;
	while(i<j){
		if(c[i]!=c[j]){
			ans+=min(a[i],a[j]);
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}
			else{
				a[j]-=a[i];
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
	cout<<ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/

