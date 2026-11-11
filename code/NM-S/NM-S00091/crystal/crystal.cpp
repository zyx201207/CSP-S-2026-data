#include<bits/stdc++.h>
using namespace std;
long long m;
long long n;
int a[500005];
long long qqq=0;
long long wh=1;
long long kkk=0;
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		for(int j=i-1;j>=0;j--){
			qqq+=abs(a[i]-a[j]);
			if(abs(qqq)>m){
				break;
			}
			wh++;
		}
		if(kkk<=wh){
			kkk=wh;
		}
		wh=1;
		qqq=0;
	}
	cout<<kkk;
	return 0;
} 
