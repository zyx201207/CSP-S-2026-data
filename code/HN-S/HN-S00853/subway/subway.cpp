#include<bits/stdc++.h>
using namespace std;
int temp,cnt=0;
long long int s[500001];

void volve(int m1,int n){
	for(int i=0;i<n;i++){
		for(int j=1;j<m1;j++){
			if(j>m1-temp){
			cout<<cnt+1;
			}
		if(	s[i]+j==s[i+1])
		{
			
			temp=j;
			s[i]=s[i+1];
			cnt++;
			break;
		}
		
		}

	}
}
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
long long 	int n=0,m=0;

	cin>>n>>m;
	int m1=m;
	for(int i=0;i<n;i++){
		cin>>s[i];
	
	} 
	
	sort(s+1,s+n+1);
	volve(m1,n);
	return 0;
} 
