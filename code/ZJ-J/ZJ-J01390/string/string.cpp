#include<iostream>
using namespace std;
int n,a[200010];
long long ans;
char c[200010];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	for(int i=1,j=n;i<j;){
		while(!a[i]&&i<j)i++;
		while(!a[j]&&i<j)j--;
		if(a[i]<=a[j]){
			if(c[i]!=c[j])ans+=a[i];
			a[j]-=a[i];
			a[i]=0;
		}
		else{
			if(c[i]!=c[j])ans+=a[j];
			a[i]-=a[j];
			a[j]=0;
		}
	}
	cout<<ans<<"\n";
	return 0;
}