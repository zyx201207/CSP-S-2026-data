#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500001],b[500001];
bool aaa(int x,int y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,aaa);
	int maxa=0;
	for(int i=1;i<n;i++){
		int x=i,z=i,T=m,ans=1;
		z++;
		for(int j=1;j<=n;j++){
			b[j]=a[j];
		}
		while(T>=0&&z<=n){
			if(b[x]==b[z]){
				ans++;
				z++;
			}else{
				b[z]++;
				T--;
			}
		}
		maxa=max(maxa,ans);
	}
	cout<<maxa;
	return 0;
}
