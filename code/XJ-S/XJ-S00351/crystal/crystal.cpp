#include <bits/stdc++.h>
using namespace std;
const int N=50000000;
long long n,m,s[N],om,summ=0;
long long finds(int mid){
	int j=mid-1,sum=1,om=m;;
	for(int j=mid-1;j>=1;j--){
		int cj=max(s[mid],s[j])-min(s[mid],s[j]);
		if(cj<=om && j>=1){
			sum++;
			om-=cj;
		}
	}
	return sum;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++){
		summ=max(summ,finds(i));
	}
	cout<<summ;
	
	return 0;
} 
