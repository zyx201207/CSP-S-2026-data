#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],sum,k=0;
char c[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=0; i<n; i++){
		scanf("%lld",&a[i]);
		cin >> c[i];
	} 
	for(long long i=0,j=0; i<n && j<a[i]; j++){
		s+=c[i];
		k++;
		if(j+1>=i){
			s+=c[i];
			i++;
			j=0;
		} 
	}
	string s1;
	for(long long i=0; i<s.size() && k>0; i++,k--){
		s1[i]=s[k];
	}
	k=s.size();
	while(k--){
		if(s[s.size()-k]!=s1[s.size()-k]) sum++;
	}
	/*for(long long i=0; i<k/2; i++){
		if(s[k]!=s[k+1-i]) sum++;
	}*/
	printf("%d",sum);
	return 0;
}
