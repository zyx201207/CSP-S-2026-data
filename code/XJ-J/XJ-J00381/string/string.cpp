
#include<bits/stdc++.h>
using namespace std;
struct node{
	long long t;
	string mark;
}pi[200006];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out ","w",stdout);
	long long  n,cnt;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>pi[i].t;
		cin>>pi[i].mark;
	}
	long long  ans=0;
	long long  len=n;
	if(len%2==0){
		len=len/2;
	}
	else{
		len=len/2+1;
	}
	int i=n;
	int j=1;
	while(i>=len&&j<=len){
		if(pi[j].t <=0){
			j++;
		}
		if(pi[i].t <=0){
			i--;
		}
		if(pi[j].mark!=pi[i].mark&&pi[j].t>pi[i].t){
			pi[j].t -=pi[i].t ;
			ans+=pi[i].t ;
			pi[i].t=0;
		}
		else if(pi[j].mark!=pi[i].mark&&pi[j].t<pi[i].t){
			pi[i].t-=pi[j].t;
			ans+=pi[j].t ;
			pi[j].t=0;
			
		}
		else if(pi[j].mark!=pi[i].mark&&pi[j].t==pi[i].t){
			pi[i].t-=pi[j].t;
			ans+=pi[j].t;
			pi[j].t=0;
			
		}
		else if(pi[j].mark==pi[i].mark&&pi[j].t==pi[i].t){
			pi[i].t-=pi[j].t;
		}
		else if(pi[j].mark==pi[i].mark&&pi[j].t>pi[i].t){
			pi[j].t-=pi[i].t;
			pi[i].t=0;
			
		}
		else if(pi[j].mark==pi[i].mark&&pi[j].t<pi[i].t){
			pi[i].t-=pi[j].t;
			pi[j].t=0;
		}
	}
	cout<<ans;
	return 0;
}


