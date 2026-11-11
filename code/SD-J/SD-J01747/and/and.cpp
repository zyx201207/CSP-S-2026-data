#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,len,And;
	cin >> n >> m;
	int s[n+5],s1[m+3],t,t1;
	for(int i=0; i<n; i++){
		cin >> len;
		s[i] = len;
	}
	t = max(s[0],s[1]);
	for (int j=0; j<m; j++){
		for(int i=0; i<n; i++){
			t = max(s[i],t);
		}
		for(int i=0; i<n; i++){
			if(s[i] == t){
				s[i] = 0;
			}
		}
		s1[j] = t;
	}
	t1 = s1[0] and s1[1];
	for(int i=0;i<m;i++){
		t1 = s1[i] and t1;
	}
	cout << t1;
	return 0;
}
