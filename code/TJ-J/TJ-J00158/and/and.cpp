#include<bits/stdc++.h>
using namespace std;
long long a[200005],m,n;
long long  max1=0;
long long change_1(long long g) {
	if(g<=1)
		return char(g);
	else
		return change_1(g/2)+((g%2)+'0');
}
long long change_2(string s) {
	long long sum;
	for(long long i=s.size(); i>=0; i--) {
		sum+=pow(2,i)*s[i];
	}
}
long long and1(long long t,long long u) {
	char x1[2000001]=&change_1(t);
	string y1[2000001]=&change_1(u);
	for(long long i=0; i<=mxx(x.size(),b.size()),i++)
		y1[i]=(x1[i]==1 && y1[i]==1)?1:0;
	return change_2(y1);

}
unsigned long long max1=0;
long long main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>m>>n;
	for(long long i=0; i<m; i++) {
		cin>>a[i];
	}
	for(long long i=0; i<n; i++) {
		for(long long i=0; i<m; i++) {
			max1=max(and1(a[i],max1),a[i]);
		}
	}
	cout<<max1;
	return 0; 
}
