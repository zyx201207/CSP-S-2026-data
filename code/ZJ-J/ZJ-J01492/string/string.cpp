#include<bits/stdc++.h>
using namespace std;
#define ll long long

int a[200010];
char c[200010];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int i=1,j,n;
	ll l=0,r=0,sum=0;
	cin>>n;
	j=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	while(i<j){
		if(a[i]-l<a[j]-r){
			if(c[i]!=c[j]) sum+=a[i]-l;
			r+=a[i]-l;
			l=0;
			i++;
		}
		else if(a[i]-l>a[j]-r){
			if(c[i]!=c[j]) sum+=a[j]-r;
			l+=a[j]-r;
			r=0;
			j--;
		}
		else{
			if(c[i]!=c[j]) sum+=a[i]-l;
			r=0;
			l=0;
			i++;
			j--;
		}
	}
	cout<<sum;
	return 0;
}
