#include<bits/stdc++.h>
using namespace std;
long long s[2000009];
int main(){
	
//	ios::sync_with_stdio(0);cin.tie(0);
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	long long c,t,n,d,h,hh,min,max;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>s[j];
			if(j==2){
				min= s[j]-s[j-1];
				max=s[j]-s[j-1];
			}
			if(j>2){
				if(s[j]-s[j-1]<min)min= s[j]-s[j-1];
				if(s[j]-s[j-1]>max)max= s[j]-s[j-1];
			}
		}
		if(min==max){
			if((n-d+min)>=0){
				cout<<n-d+min<<endl;
				continue;
			}
			else {
				cout<<"0"<<endl;
				continue;
			}
		}
		if(max<=d and (s[n]-s[1])<=2*d){
			if((n-d+min)>=0){
				cout<<n-d+min<<endl;
				continue;
			}
			else {
				cout<<"0"<<endl;
				continue;
			}
		}
		sort(s+1,s+1+n);
		int cs=1;
		int cnt=0,cnnt=0;
		h=0;
		for(int j=1;j<=n;j++){
			h=0;
			h=upper_bound(s+1,s+1+n,s[j]+d)-s;
			cnnt=h;	
			while(h<=n){
				h=upper_bound(s+1,s+1+n,s[j]+d)-s;
				if(h-cnnt<1)cnt++;
				else break;
				cnnt=h;
				s[j]+=d;
			}
		}
		cout<<cnt<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
