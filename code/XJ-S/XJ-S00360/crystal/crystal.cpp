#include<bits/stdc++.h>
using namespace std;
const long long P=5e5+5;
long long num[P],sum[P],ans=LLONG_MIN,x;
int main(){
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		sum[i]=num[i];
	}
	sort(num+1,num+n+1);
	int l=1,r=n,mid,k=0;
	while(l<=r){
		for(int i=1;i<=n;i++){
		    sum[i]=num[i];
	    }
		x=0,k=0;
		mid=(l+r)/2;
		for(int i=1;i<mid;i++){
			if(num[mid]-num[i]>m)continue;
			else{
				k+=(num[mid]-num[i]);
				sum[i]=num[mid];
			} 	
		}
		if(k>m)r=mid-1;
		else if(k<=m){
			for(int i=1;i<=n;i++){
			if(sum[i]==num[mid])x++;
			if(sum[i]>num[mid])break;
			l=mid+1;
		    }
		}
		
		ans=max(x,ans);
	}
	cout<<ans;
	return 0;
} 
