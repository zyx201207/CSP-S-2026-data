//SN-J00814
//吴皓轩 
//西安交通大学附属中学 
#include<bits/stdc++.h>
using namespace std;
long long n,cnt,len,len1,ans;
string s,a;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>cnt>>a;
		len=cnt-1;
		for(long long j=1;j*2<=n;j*=2){
			a+=a;
		}
		len1=a.size();
		for(long long j=len1;j<=len;j++){
			a+=a[0];
		}
		s+=a;
    }
    for(long long i=0;i<n;i++){
    	if(s[i]!=s[s.size()-i-1])ans++;
	}
	cout<<ans;
	return 0;
}
