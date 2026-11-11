#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
bool cmp(int x,int y){
	return x<y;
}
long long n,m;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	long long ans=0;
	for(int i=2;i<=n;i++){
		if(a[i-1]==a[i]){
			ans++;	
		}else{
			break;
			
		}
		
	}
	long long sum=0;
	long long cnt=0;
	long long w=0;
	if(n%2==0){
		long long s=n/2;
		long long k=0;
		long long p=0;
		
		for(int i=1;i<s;i++){
			sum+=a[i];
			if(sum+=m>=a[s]*(s-1)){
				cnt++;	
				
			}
			
			
		}for(int i=s+1;i<=n;i++){
			long long b=sum+m-a[s]*(s-1)-w;
			w=a[i]-a[s]+s;
			if(b>=w){
				p++;
			}else{
				break;
			}
		}
		
		sum+=m;
		if(sum>=a[s]*(s-1)){
			cout<<s+p;
		}else{
			cout<<cnt+p;
		}
	}else{
		long long s=n+1;
		s=s/2;
		long long k=0;
		long long p=0;
		
		for(int i=1;i<s;i++){
			sum+=a[i];
			
			if(sum+=m>=a[s]*(s-1)){
				cnt++;	
				
			}
			
			
		}
		for(int i=s+1;i<=n;i++){
			long long b=sum+m-a[s]*(s-1)-w;
			w=a[i]-a[s]+s;
			if(b>=w){
				p++;
			}else if(a[i]==a[s]){
				p++;
			
			}else{
				break;
			}
		}
		sum+=m;
		if(sum>=a[s]*(s-1)){
			cout<<s+p;
		}else{
			cout<<cnt+p;
		}
	}
	if(ans==n-1){
		cout<<n;
	}
	
	
	return 0;
}
