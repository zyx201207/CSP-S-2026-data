#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a,b;
	cin >> a >> b;
	long long c[a+1];
	for(int i=1;i<=a;i++)
        cin >> c[i];
    sort(c,c+a);
    cout << c[a+1];
	return 0;
}
