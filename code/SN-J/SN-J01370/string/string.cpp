#include<bits/stdc++.h> 

using namespace std;

long long n,a,l,r,jieguo,Long;
string s;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		cin>>c;
		Long+=a;
		s+=c*a;
	}
	l=0;
	r=Long-1;
	while(l<r){
		if(s[l]!=s[r])
			jieguo++;
			
		r--;
		l++;
	}
	cout<<jieguo;
return 0;
}

