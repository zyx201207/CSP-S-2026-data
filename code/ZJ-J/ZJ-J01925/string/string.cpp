#include<bits/stdc++.h>
using namespace std;
long long n,a[200009],sum,ans;
char c[200009];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		
		sum+=a[i];
	}
	if(sum>9e9){
		cout<<sum/2;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	else {
		for(int i=1;i<=n;i++){
		while(a[i]--)s+=c[i];
	}
	}
	long long l=0,r=s.size()-1;
	while(l<r){
		if(s[l]!=s[r])ans++;
		l++;
		r--;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}