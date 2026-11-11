#include<bits/stdc++.h>
using namespace std;
int a[200005],i=1,j;
long long n,ans;
char b[200005]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int k=1;k<=n;k++){
		cin>>a[k]>>b[k];
	}
	j=n;
	while(true){
		if(a[i]>=a[j]){
			if(b[i]!=b[j])ans+=a[j];
			a[i]-=a[j];
			j--;
		}
		else{
			if(b[i]!=b[j])ans+=a[i];
			a[j]-=a[i];
			i++;
		}
		if(i>=j)break;
	}
	cout<<ans;
	return 0;
}
