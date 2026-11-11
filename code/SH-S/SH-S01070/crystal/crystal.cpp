#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int a[500005],n,m,k,p,ans;
bool flag=false;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	p=a[2]-a[1];
	a[n+1]=a[n]+p;
	for(int i=2;i<=n+1;i++){
		if(a[i]-a[i-1]!=p){
			flag=true;
		}
	}
	if(flag==false){
		int count=1,cnt=0;
		while(m>=cnt&&count<=n){
			cnt+=p*count;
			count++;
		}
		ans=count-1;
	}
	else{
		n%2==0?k=n/2:k=n/2+1;
		int count=1,cnt=0,ct=k-1;
		while(m>=cnt){
			cnt+=a[k]-a[ct];
			count++;
			ct--;
		}
		ans=count;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
