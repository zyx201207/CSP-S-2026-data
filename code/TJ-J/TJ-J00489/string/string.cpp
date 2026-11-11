#include<bits/stdc++.h>
using namespace std;
struct node{
	long long n;
	char y;
}s[2000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long k,ans=0,sum=0;
	cin>>k;
	
	for(long long i=1;i<=k;i++){
		cin>>s[i].n;
		cin>>s[i].y;
		
	}
	long long l=1;
	long long r=k;
	while(l<r){
		
		if(s[l].n>s[r].n){
			
			s[l].n-=s[r].n;
			if(s[l].y!=s[r].y){
				ans+=s[r].n;
				
			}
			r--;
		}else if(s[l].n<s[r].n){
			s[r].n-=s[l].n;
			if(s[l].y!=s[r].y){
				ans+=s[l].n;
				
			}
			l++;
		}else{
			if(s[l].y!=s[r].y){
				ans+=s[r].n;
			}
			r--;
			l++;
		}
		
	}
	cout<<ans;
	return 0;
}
