#include<iostream>
#include<cstring>
using namespace std;
int n;
long long ans;
char s[200010];
string l;
long long jishu=1;
long long num[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string,out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>num[i]>>s[i];
	} 
	if(n%2!=0){
		long long cnt=0,ji=0;
		for(int i=1;i<=n/2+1;++i){
			if(num[i]>num[n-cnt]){
				ji=num[i]-num[n-cnt];
				num[n-cnt]+=num[i]-num[n-cnt];
				num[n-cnt-1]-=ji;
			}else if(num[i]<num[n-cnt]){
				num[i]+=num[n-cnt]-num[i];
				num[i+1]-=num[n-cnt]-num[i];
			}
			if(s[i]!=s[n-cnt]){
				ans+=num[i];
			}
			if(num[i]<0){
				ans+=num[i];
			}
	

		
			++cnt;
		}
	}else if(n%2==0){
		long long cnt=0,ji=0;
		for(int i=1;i<=n/2;++i){
			if(num[i]>num[n-cnt]){
				ji=num[i]-num[n-cnt];
				num[n-cnt]+=num[i]-num[n-cnt];
			}else if(num[i]<num[n-cnt]){
				ji=num[n-cnt]-num[i];
				num[i]+=num[n-cnt]-num[i];
			}
			if(s[i]!=s[n-cnt]){
				ans+=num[i];
				ans-=ji;
			}

			++cnt;
		}
		
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
