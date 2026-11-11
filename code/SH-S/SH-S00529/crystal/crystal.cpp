#include<bits/stdc++.h>
using namespace std;
int n,m;
int c[500005],num[500005];
int ans;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>c[i];
		num[c[i]]++;
	}
	sort(c+1,c+1+n);
	int s=m;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			int k=c[i]-c[j];
			if(m-k>=0){
				m-=k;
			}
			if(m==0){
			    ans=i;
				if(num[c[i]]>0){
					ans+=num[c[i]]-1;
				}
				cout<<ans;
				return 0;
			}
			if(m<0){
				ans=i-1;
				if(num[c[i]]>0){
					ans+=num[c[i]]-1;
				}
				cout<<ans;
				return 0;
			}
			
		}
		m=s;
	}
	return 0;
} 
