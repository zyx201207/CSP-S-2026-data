#include<bits/stdc++.h>
using namespace std;
char a[10],b[10],c[10],d[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	bool flag = 1;
	for(int i = 0;i<=1;i++)if(a[i] != c[i])flag = 0;
	cout << flag;
	for(int i = 0;i<=1;i++)if(b[i] != d[i])flag = 0;
	cout << flag;
	if((b[2] <= 'C' && d[2] > 'C') || (b[2] > 'C' && d[2] <= 'C'))flag = 0;
	cout << flag;
	if(flag && abs(b[2] - d[2]) == 1)cout << 1;
	else cout << 0;
	return 0;
	cout << endl;
}