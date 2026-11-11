#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500100],s[500100],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	a[0]=a[1];s[1]=0;
	for(long long i=2,j=1;i<=n;i++){
		s[i]=s[i-1]+(a[i]-a[i-1])*(i-j);
		if(s[i]>m){
			while(s[i]>m){
				s[i]=s[i]-abs(a[i]-a[j]);
				j++;
			}
			ans=max(i-j+1,ans); 
		}else{
			ans=max(i-j+1,ans);
		}
	}
	cout<<ans<<endl;
	return 0;
}