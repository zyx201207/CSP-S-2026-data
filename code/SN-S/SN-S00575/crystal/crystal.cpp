#include<bits/stdc++.h>
using namespace std;
int n,c,zong=0,beifen=0,b=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>c;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[j]<a[j-1]){
				swap(a[j],a[j-1]);
			}
		}
	}int len=sizeof(a)/sizeof(a[0]);
	int leng=len/2;
	for(int i=0;i<leng;i++){
		if(a[i]<0){
			beifen=a[leng]+a[i];
			zong=zong+beifen;
			a[i]+=beifen;
		}else{
			beifen=a[leng]-a[i];
			zong=zong+beifen;
			a[i]+=beifen;
		}
	}for(int i=0;i<=n;i++){
		if(a[i]==a[leng]){
			b++;
			
		}
	}if(a[0]==0){cout<<b+1;
	}else{
		cout<<b;
	}
	return 0;
}
