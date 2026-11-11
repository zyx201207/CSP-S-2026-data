#include<bits/stdc++.h>
using namespace std;
long long int n,a[200005],ans=0,sum,qm,hm;
char s[2000000005];
string s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		ans+=a[i];
		for(int j=1;j<=a[i];j++) s1+=s[i],s2+=s[i];
	}
	if(ans%2==0) hm=ans/2+1,qm=ans/2;
	else hm=ans/2+2,qm=ans/2;
	for(int i=hm-1,j=qm-1;i<ans;i++){
		s2[i]=s2[j];
		j--;
	}
	for(int i=0;i<ans;i++){
		if(s2[i]!=s1[i]) sum++;
	}
	cout<<sum;
	return 0;
} 
