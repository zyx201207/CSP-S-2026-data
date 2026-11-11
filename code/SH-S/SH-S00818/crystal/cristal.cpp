#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
long long n,m;
long long a[10005],b[10005];
//Oct31==Dec25?
int main(){
	freopen("cristal.in","r",stdin);
	freopen("cristal.out","w",stdout);
	cin>>n>>m;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>2){
			if(a[i-1]-a[i-2]!=a[i]-a[i-1]){
				flag=false;
			}
		}
	}
	if(flag){
		long long d=a[2]-a[1];
		long long s=m/d;
		long long sum=0,i=0;
		while(sum<s){
			i++;
			sum=sum+i;
			
		}
		if(sum>s){
			cout<<i<<endl;
		}else if(sum==s){
			cout<<i+1<<endl;
		}
		return 0;
	}
	sort(a+1,a+n+1);
	long long maxx=0;
	for(long long i=a[1];i<=a[n];i++){
		long long cnt=0;
		memset(b,0,sizeof(b));
		for(int j=1;j<=n;j++,cnt++){
			if(a[j]<=i){
				b[j]=i-a[j];
			}else{
				break;
			}	
		}
		long long sum=0;
		long long ans=0;
		for(int j=cnt;j>=1;j--){
			if((sum+b[j])<=m){
				sum=sum+b[j];
				ans++;
			}	
		}
		maxx=max(maxx,ans);
	}
	cout<<maxx<<endl;
	return 0;
} 
