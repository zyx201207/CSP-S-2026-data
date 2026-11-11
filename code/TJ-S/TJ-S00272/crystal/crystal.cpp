#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
long long m,a[500005]={},b[500005][2]={};
bool cmp(int a,int b){
	return a<=b;
}
int lg(long long sum){
	int d=0;
	while(sum>1){
		sum/=2;
		d++;
	}
	return d;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int l=0,r=0,bv=0;
	long long s,ans=0;
	bool f=true;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	if(n>2){
		for(int i=1;i<n;i++){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
				f=false;
				break;
			}
		}
	}
	if(f==false || n<=2){
		b[0][0]=1;
		b[0][1]=a[0];
		for(int i=1;i<n;i++){
			if(a[i]==a[i-1]) b[bv][0]++;
			else{
				bv++;b[bv][0]=1;b[bv][1]=a[i];
			}
		}
		for(int i=bv;i>=0;i--){
			s=b[i][0];
			int um=m,j=i-1;
			while(j>=0){
				if(b[j][0]*(b[i][1]-b[j][1])<=um){
					um-=b[j][0]*(b[i][1]-b[j][1]);
					s+=b[j][0];
					if(um==0) break;
				}
				else{
					s+=um/(b[i][1]-b[j][1]);
					break;
				}
				j--;
			}
			ans=max(ans,s);
		}
		cout<<ans<<endl;
	}
	else{
//		cout<<"*"<<endl;
		long long jg=a[1]-a[0];
		ans=(lg(jg*jg+4*jg*jg*m)+jg)/(2*jg);
		cout<<ans<<endl;
	}
	return 0;
}
