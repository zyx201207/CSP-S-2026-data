#include<bits/stdc++.h>
using namespace std;
long long c,d,a,b,sum,s,ans,m=10000000000000,n=-10000000000000,t[10000001],l[10000001],r[10000001],aaa,aa;
int main(){
	freopen("cryctal.in","r",stdin);
	freopen("cryctal.out","w",stdout);
	for(int i=0;i<=10000000;i++){
		t[i]=0;
		l[i]=0;
		r[i]=0;
	}
	cin>>a>>b;
	if(b>100000000){
		for(int i=1;i<=a-2;i++){
			cin>>t[1];
		}
		cin>>c>>d;
		sum=a;
		if(d>c)
			aaa=d-c;
		else
			aaa=c-d;
		while(b>=ans&&sum>0){
			ans+=aaa;
			if(d>c)
				aaa+=d-c;
			else
				aaa+=c-d;
			sum-=1;
			aa+=1;
		}
		if(b<ans){
			cout<<aa-1;
			return 0;
		}
		else{
			cout<<aa;
			return 0;
		}
	}
	else{
		for(int i=1;i<=a;i++){
			cin>>t[i];
			l[t[i]]++;
			m=min(m,t[i]);
			n=max(n,t[i]);
		}
		for(int i=m;i<=n;i++){
			if(l[i]!=0){
				sum=i-1;
				aaa=l[i];
				while(b>=ans&&sum>=m){
					if(l[sum]!=0){
						s=l[sum];
						while(b>=ans&&s>0){
							ans+=r[sum];
							aaa+=1;
							s-=1;
						}
					}
					sum-=1;
				}
				if(b<ans){
					ans=0;
					aaa-=1;
					aa=max(aaa,aa);
					aaa=0;
				}
				else if(sum<m){
					ans=0;
					aa=max(aaa,aa);
					aaa=0;
				}
			}
			for(int j=m;j<=i;j++){
				r[j]+=1;
			}
		}
		cout<<aa;
		return 0;
	}
} 
