#include<bits/stdc++.h>
using namespace std;
const int N=3*1e5+101;
long long n;
long long a[N];
char c[N];
long long cnt;
int i=1,j;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	
	
	j=n;

	while(i<j){
		if(c[i]!=c[j])cnt+=min(a[i],a[j]);
		if(a[i]>a[j]){
			a[i]-=a[j];
			j--;
		}else if(a[j]>a[i]){
			a[j]-=a[i];
			i++;
		}else{
			i++;j--;
		}
	}
	cout<<cnt;
	return 0;
}
