#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,s[N];
char z[N];
long long zo=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i]>>z[i];
	int l=1,r=n;
	while(l<r)
		if(z[l]==z[r])
			if(s[l]<s[r]){
				s[r]-=s[l];
				l++;
			}
			else if(s[r]<s[l]){
				s[l]-=s[r];
				r--;
			}
			else
			{
				r--;
				l++;
			}
		else
			if(s[l]<s[r]){
				zo+=s[l];
				s[r]-=s[l];
				l++;
			}
			else if(s[r]<s[l]){
				zo+=s[r];
				s[l]-=s[r];
				r--;
			}
			else
			{
				zo+=s[l];
				r--;
				l++;
			}
	cout<<zo;
	return 0;
}
