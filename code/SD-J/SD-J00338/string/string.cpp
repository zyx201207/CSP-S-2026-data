#include<bits/stdc++.h>
using namespace std;
long long n,a[200002],ansl,ansr,l,r,sum;
char c[200002],cl,cr;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(i!=1&&c[i]==c[i-1]){
			a[i-1]+=a[i];
			i--;
			n--;
		}
	}
	l=1;
	r=n;
	ansl=a[1];
	ansr=a[r];
	while(l<r){
		long long x=min(ansl,ansr);
		if(c[l]!=c[r])sum+=x;
		ansl-=x;
		ansr-=x;
		if(ansl==0){
			ansl=a[++l];
		}
		if(ansr==0){
			ansr=a[--r];
		}
	}
	cout<<sum;
	return 0;
}
