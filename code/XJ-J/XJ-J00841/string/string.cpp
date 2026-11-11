#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int t;
int a[N];
char c[N];
long long ans;
int main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	for (int i=1;i<=t;i++){
		cin>>a[i]>>c[i];
	}
	int i=1;
	int j=t;
	while (i<j){
		if (c[i]!=c[j]){
			if (a[i]>a[j]){
				ans+=a[j];
				a[i]-=a[j--];
			}else if(a[i]<a[j]){
				ans+=a[i];
				a[j]-=a[i++];
			}else {
				ans+=a[i];
				i++;
				j--;
			}
		}
	}
	

	cout<<ans;

	
	
	return 0;
} 

