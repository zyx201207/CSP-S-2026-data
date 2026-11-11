#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	for(int i= 1;i <= n; i++){
		cin >> a[i];
		b[i] = a[i];
	}
	sort (b+1,b + n + 1);
	m_num[1] = b[1];
	for(int i = 1; i <= n; i++){
		if(m_num[c-1] != b[i]){
			m_num[c] = b[i];
			c++;
			for(int j = i; j <= n; i++)
		}
	}
	return 0;
}
