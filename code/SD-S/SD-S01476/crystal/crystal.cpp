#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans,s[500010],k[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}stable_sort(a+1,a+n+1);
	long long last=1,lastused=0;
	for(int i=1;i<n;i++){
		k[i]=a[i+1]-a[i];
		s[i]=s[i-1]+k[i];
	}for(int i=1;i<n;i++){
		if(n-i+1<ans){
			break;
		}long long used=0,j;
		if(i>1){
			used=lastused-s[last]+s[i-2];
		}for(j=last;j<n;j++){
			if((j-i+1)*k[j]>m-used){
				break;
			}used+=(j-i+1)*k[j];
		}ans=max(ans,j-i+1);
		last=j-1;
		lastused=used;
	}cout<<ans;
	return 0;
}
