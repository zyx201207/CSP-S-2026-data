#include<bits/stdc++.h>
using namespace std;
long long n,a[200010];
char s[200010];
long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	int i=1,j=n;
	while(1){
		// cout<<i<<' '<<j<<' '<<sum<<'\n';
		if(i>=j)break;
		if(a[i]<a[j]){
			if(s[i]!=s[j])
				sum+=a[i];
			a[j]-=a[i];
			i++;
		}else if(a[i]>a[j]){
			if(s[i]!=s[j])
				sum+=a[j];
			a[i]-=a[j];
			j--;
		}else{
			if(s[i]!=s[j])
				sum+=a[j];
			i++;j--;
		}
		
	}
	cout<<sum;
	return 0;
}
