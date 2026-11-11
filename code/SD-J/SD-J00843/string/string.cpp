#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005],b[200005];
char c[200005],d[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		b[n-i-1]=a[i];
		d[n-i-1]=c[i];
	}
	ll sum=0;
	ll lp=a[0];
	int i=0,j=0;
	while (1){
		if(lp>b[j]){
			if(c[i]!=d[j])sum+=b[j];
			lp-=b[j];
			b[j]=0;
			j++;
			if(j>=n||i>=n)break;
		}else if(lp==b[j]){
			if(c[i]!=d[j])sum+=b[j];
			b[j]=0;
			j++;
			i++;
			if(j>=n||i>=n)break;
			lp=a[i];
		}else{
			if(c[i]!=d[j])sum+=lp;
			b[j]-=lp;
			i++;
			if(j>=n||i>=n)break;
			lp=a[i];
		}
	}
	cout<<sum/2;
	return 0;
}
