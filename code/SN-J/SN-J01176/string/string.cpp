#include <iostream>
#include <cstring>
using namespace std;
const long long N=2e5+7;
long long n;
long long a[N];
char s[N];
long long m;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		m+=a[i];
	}
	long long i=1;
	long long si=a[1];
	long long j=n;
	long long sj=a[n];
	while(i<j){
		if(s[i]==s[j]){
			long long u=min(si,sj);
			si-=u;
			sj-=u;
			if(si==0){
				i++;
				si=a[i];
			}
			if(sj==0){
				j--;
				sj=a[j];
			}
		}else{
			long long u=min(si,sj);
			ans+=u;
			si-=u;
			sj-=u;
			if(si==0){
				i++;
				si=a[i];
			}
			if(sj==0){
				j--;
				sj=a[j];
			}
		}
	}
	cout<<ans;
}
