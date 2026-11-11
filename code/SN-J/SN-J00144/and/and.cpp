#include <bits/stdc++.h>
using namespace std;
int n , m , s;
struct node{
	int a , b;
}c[200005];
bool cmp(node x , node y){
	if(x.b == x.b) return x.a > y.a;
	else return x.b > y.b;
}
boll cmm(node x , node y)
{
	return x.a > y.a;
}
int main(){
	freopen("and3.in" , "r" , stdin);
	freopen("and.out" , "w" , stdin);
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++) 
	{
		cin >> c[i].a;
		int x = c[i].a;
		while(x > 0)
		{
			c[i].b += x % 2;
			x /= 2;
		}
	}
	sort(c , c + n , cmp);
	if(m == 1)
	{
		sort(c , c + n , cmm);
		cout << c[0].a;
	}
	s = c[0].a;
	for(int i = 1 ; i < m ; i++) s = s & c[i].a;
	cout << s;
	return 0;
}

