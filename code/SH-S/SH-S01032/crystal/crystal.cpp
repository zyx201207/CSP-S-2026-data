#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int a[500005];
	long long m,cnt=1;
	long long c;
	cin>>m>>c;
	for(long long i=1;i<=m;i++){
		cin>>a[i];
	}
	sort(a+1,a+m+1);
	long long cn=1;
	for(long long i=m;i>1;i--){
		
		for(long long j=i-cn;j>0;j--){
			
			if((a[i]-a[j])<=c){
				c=c-(a[i]-a[j]);
				cn++;
			}else{
				break;
			}
		}
		
		cnt=max(cnt,cn);
		cn--;
		c+=cn*(a[i]-a[i-1]);
	}
	cout<<cnt;
	return 0;


	fclose(stdin);
	fclose(stdout);
} 
