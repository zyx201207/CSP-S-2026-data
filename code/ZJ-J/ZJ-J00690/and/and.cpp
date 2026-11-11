#include<bits/stdc++.h>
using namespace std;
int a[200007],b[200007],n,l,mx,k,ans;
void mc(){
	for(int i=1;i<=l;i++){
		mx=max(a[i],mx);
	}
	int i;
	for(i=1;mx>i;i*=2);
	mx=i/2;
}
void op(int p){
	for(int i=1;i<p;i++){
		a[i]=b[i];
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>l>>k;
	for(int i=1;i<=l;i++){
		cin>>a[i];
	}
	mc();
	for(;mx!=0;mx/=2){
		int p=1;
		for(int i=1;i<=l;i++){
			if(a[i]>=mx){
				a[i]-=mx;
				b[p++]=a[i];
			}
		}
		if(p>k){
			ans+=mx;
			l=p-1;
			op(p);
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}