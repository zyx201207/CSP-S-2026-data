#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long ans=0;
	int i=1,j=n;
	while(i<j){
		while(a[j]<=a[i]&&i<j){
			if(c[i]!=c[j])ans+=a[j];
			a[i]-=a[j],j--;
		}
		if(c[i]!=c[j])ans+=a[i];
		a[j]-=a[i];
		i++;
	}
	cout<<ans<<endl;
	return 0;
} 
