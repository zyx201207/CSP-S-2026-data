#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int n,m,a[5005],js=0,ct[5005],jct=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(a[n/2]==a[n/2+1]){
		js++;
	}
	if(a[n/2]==a[0]){
		cout<<n/2;
		return 0;
	}
	if(a[n/2]==a[n/2-1]){
		js++;
	}
	for (int i=0;i<n/2;i++){
		for (int j=0;j<m+1;m--){
			if(a[n/2]-a[i]>m/3){
				ct[i]=i;
				jct++;
				break;
			}
			if(a[i]==a[n/2]){
				js++;
				break;
			}
			a[i]++;
		}
	}
	sort(ct,ct+jct,cmp);
	for (int i=0;i<jct;i++){
		if(a[n/2]>=a[ct[i]]){
			js++;
			m-a[ct[i]];
		}
	}
	cout<<js+1;
	return 0;
} 
