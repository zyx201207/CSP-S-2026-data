#include <bits/stdc++.h>
using namespace std;
int n,s[200200];
char c[200200];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)  cin>>s[i]>>c[i];
	int i=1;
	while(i<n){
		if(s[i]<s[n]){
			if(int(c[i])!=int(c[n]))  ans+=s[i];
			s[n]-=s[i],i++;
		}
		else if(s[i]>s[n]){
			if(int(c[i])!=int(c[n]))  ans+=s[n];
			s[i]-=s[n],n--;
		}
		else{
			if(int(c[i])!=int(c[n]))  ans+=s[i];
			i++,n--;
		}
//		cout<<i<<" "<<n<<" "<<ans<<"\n";
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
