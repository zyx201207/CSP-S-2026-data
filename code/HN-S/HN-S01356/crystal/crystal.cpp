#include<bits/stdc++.h>
using namespace std;
signed long long m,n,a[500005]={},s[500007]={};
bool cmp(signed long long a,signed long long b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(signed long long i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,cmp);
	s[0]=0;
	for(signed long long i=1;i<n;i++) {
		s[i]=s[i-1]+(a[i]-a[i-1])*i;
	}for(signed long long i=0;i<n;i++) {
		if(s[i]>m){
			signed long long rm=0,kt=0,cd=1,j;
			for(int j=i-1;j>=0;j--){
				rm+=(a[i]-a[j]);
				if(m-rm<0){
					kt=i-j-1;
					cout<<i<<' '<<j<<' ';
					break;
				}
			}j=i;
			while(a[j]==a[j+1]) {
				cd++; j++;
			}
			cout<<max(i,kt+cd)<<' '<<kt<<' '<<cd;
			return 0;
		} 
	}cout<<n;
	return 0;
} 
