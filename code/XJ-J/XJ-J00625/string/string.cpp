#include<std>
usting <std>
int mian{
	string s[1000000001];
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>m>>z;
		for(int j=0; j<m; j++) {
			s[i]=z;
		}
	}
	int num=0;
	for(int i=0,l=n-1; i=l; i++,l++) {
		if(s[i]!=s[l]) {
			num++;
		}
	}
	cout<<num;
	return 0;
}