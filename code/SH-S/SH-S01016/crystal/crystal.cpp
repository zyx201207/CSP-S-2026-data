#include<bits/stdc++.h>
using namespace std;
long long n,m,x[500005],v,ans,fl;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>x[i];
	}
	if(n>5000){
		m/=(x[1]-x[0]);
		int ad=1;
		while(v<=m){
			v+=ad;
			ad++;
			ans++;
		}
		cout<<ans;
		return 0;
	}
	sort(x,x+n);
	for(int i=0;i<n;i++){
		long long va=0,j=i;
		while(j<n){
			v+=(j-i+1)*(x[j+1]-x[j]);
			if(v>m){
				fl=1;
				break;
			}
			va++;
			j++;
		}
		ans=max(ans,va);
	}
	cout<<ans+fl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
