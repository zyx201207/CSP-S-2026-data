#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,n,L,cnt = 0,ac1 = 0,ac2 = 0;
	string s,z1,z2;
	char c;
	cin>>n;
	for (long long i = 1;i <= n;i++){
		cin>>a>>c;
		for (long long j = 0;j < a;j++){
			s[j] = c; 
		}
	}
	L = s.size();
	if (L % 2 == 0){
		for (long long i = 0;i < L / 2;i++){
			z1 = s[i +  L / 2];
			z2 = s[i];
		}
		for (long long i = 0;i < L / 2;i++){
			if (s[i] != z1[i]) ac1++;
			if (s[i + L / 2] != z2[i]) ac2++;
		}
		if (ac1 < ac2) cout<<ac1;
		else cout<<ac2;
	}
	else {
		for (long long i = 0;i < L / 2;i++){
			z1[i] = s[i +  L / 2 + 1];
			z2[i] = s[i];
		}
		for (long long i = 0;i < L / 2;i++){
			if (s[i] != z1[i]) ac1++;
			if (s[i + L / 2] != z2[i]) ac2++;
		}
		if (ac1 < ac2) cout<<ac1;
		else cout<<ac2;	
	}
	return 0;
}

