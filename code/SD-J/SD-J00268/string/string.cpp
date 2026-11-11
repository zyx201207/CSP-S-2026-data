#include <bits/stdc++.h>
using namespace std;
const int MX=1e6+10;
int n;
long long sum;
struct dol{
	long long len;
	char nm;
};
dol s[MX];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		sum+=a;
		if(c==s[i-1].nm&&i-1>=1){
			s[i-1].len+=a;
			i--;
			n--;
		}else{
			s[i].len=a;
			s[i].nm=c;
		}
	}
	long long f=sum%2,ans=0,i=1,j=n;
	sum/=2;
	while(sum>0){
		if(s[i].len>=sum){
			if(s[i].nm!=s[j].nm){
				ans+=min(s[i].len,s[j].len);
			}
			sum-=s[j].len;
			s[i].len-=s[j].len;
			s[j].len=0;
			j--;
		}else if(s[j].len>sum){
			if(s[i].nm!=s[j].nm){
				ans+=min(s[i].len,s[j].len);
			}
			sum-=s[i].len;
			s[j].len-=s[i].len;
			s[i].len=0;
			i++;
		}else if(s[i].len>=s[j].len){
			if(s[i].nm!=s[j].nm){
				ans+=s[j].len;
			}
			s[i].len-=s[j].len;
			sum-=s[j].len;
			s[j].len=0;
			j--;
		}else if(s[j].len>s[i].len){
			if(s[i].nm!=s[j].nm){
				ans+=s[i].len;
			}
			s[j].len-=s[i].len;
			sum-=s[i].len;
			s[i].len=0;
			i++;
		}
	}
	cout<<ans;
	return 0;
} 
