#include<bits/stdc++.h>
using namespace std;
long long n , a[200005] , sum;
char c[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>a[i]>>c[i];
	for(int i = 1;i<=n;i++){
		while(a[i]--)s+=c[i];
	}
	for(int i = 0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i])sum++;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
