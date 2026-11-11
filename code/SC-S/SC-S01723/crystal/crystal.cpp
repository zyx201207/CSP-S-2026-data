#include<bits/stdc++.h>
using namespace std;
int n,c[500005],cnt,tnc;
long long m,lans,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	while(1){
		if(tnc==n-1){
			tnc=0;
			if(cnt==0){
				break;
			}
			cnt=0;
		}
		if(c[tnc]>c[tnc+1]){
			int a=c[tnc];
			c[tnc]=c[tnc+1];
			c[tnc+1]=a;
			cnt++;
		}
		tnc++;
	}
	for(int i=1;i<n;i++){
		cnt=0;
		ans=0;
		for(int j=i-1;j>=0;j--){
			cnt+=c[i]-c[j];
			ans++;
			if(cnt>m){
				break;
			}
		}
		lans=max(ans,lans);
	}
	int yu=0;
	for(int i=1;i<n-1;i++){
		if(c[i]-c[i-1]!=c[i+1]-c[i]){
			yu++;
		} 
	} 
	if(yu==0){
		cout<<lans;
	}else{
		cout<<lans+1;
	} 
	return 0;
}