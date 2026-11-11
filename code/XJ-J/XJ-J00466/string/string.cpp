#include<bits/stdc++.h>
using namespace std;
long long n,m[200005],cnt;
long long l,r;
char s[200005];
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>m[i];
		cin>>s[i];
	}
	l=1;
	r=n;
	while(l<=r){
		if(m[l]>m[r]){
			m[l]-=m[r];
			if(s[l]!=s[r]) cnt+=m[r];
			m[r]=0;
			r--;
		}else{
			m[r]-=m[l];
			if(s[l]!=s[r]) cnt+=m[l];
			m[l]=0;
			l++;
		}
	}
	cout<<cnt;
	return 0;
} 
//9:29 no problem!!!
