#include <bits/stdc++.h>
using namespace std;

int m,a,k;
long long n;
string s;
int c=0;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	int b=m;
	for(int i=1;i<=b;i++){
		cin>>s[i];
	}
	for(int i=1;i<=b;i++){
		if(m>0&&s[s.size()/2+1]!=s[s.size()/2]&&s[s.size()/2-1]!=s[s.size()/2]){
			k=s[s.size()/2]-s[s.size()/2-1];
			m=m-k;
		}
		c++;
	}
	cout<<c;
	return 0;
}

