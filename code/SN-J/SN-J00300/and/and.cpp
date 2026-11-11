#include<bits/stdc++.h>
using namespace std;
int n,m,d[1000010],mi=2e9,cnt;
bool check(int a){
	int cnt=0;
	while(a){
		a/=2;
		cnt++;
	}
	int ans=1;
	for(int i=1;i<=cnt;i++)ans*=2;
	return ans!=a;
}
int main(){
   freopen("and.in","w",stdin);
   freopen("and.out","r",stdout);
  cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>d[i];
  sort(d+1,d+n+1);
  for(int i=n;i>=1;i--){
  	if(cnt<m){
  		cnt++;
		if(check(d[i])==1)mi=min(mi,d[i]);
	}
	if(i==1 && cnt<m){
		for(int j=1;j<=n;j++){
		  if(cnt<m){
  		    cnt++;
		    if(check(d[i])==0)mi=min(mi,d[i]);
	      }	
		}
	}
  }
  cout<<mi;
return 0;
}
