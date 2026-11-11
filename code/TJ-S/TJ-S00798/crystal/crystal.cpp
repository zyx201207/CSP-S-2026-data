#include<bits/stdc++.h>
using namespace std;
bool vmp(int x,int y){
	return x<y;
}
long long a[500005],cf[500005],tj[500005],tj2[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m,n,m2;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,vmp);
	int js=0,k=-1,sum;
	for(int i=0;i<=n+1;i++){
		if(a[i]!=tj[js]){
			js++;
			tj[js]=a[i];
			tj2[js]=i-1;
		}
	}
	a[0]=a[1];
	for(int i=1;i<=js;i++){
		m2=m;
		sum=0;
		for(int j=tj2[i];j>0;j--){
			if(m2<a[j]-a[j-1]){
				break;
			}
			sum++;
			m2-=a[j]-a[j-1];
		}
		if(k<=sum){
			k=sum;
		}
	}
	cout<<k;
return 0;
} 
