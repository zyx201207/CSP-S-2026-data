#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, cnt = 0, a[2000100], a1[1000100], a2[1000100], a3[1000100];
char c[2000100], c1[1000100], c2[1000100], c3[1000100];
ll sum = 0;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(ll i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	
	ll sum_back = sum / 2;
	for(ll i = 1; i <= n / 2 + 1; i++)
	{
		if(sum_back > a[i])
		{
			a1[i] = a[i];
			c1[i] = c[i];
			sum_back -= a[i];
		}
		else
		{
			a1[i] = sum_back;
			c1[i] = c[i];
		}
	}
	sum_back = sum / 2;
	for(ll i = n; i >= n / 2 + 1; i--)
	{
		if(sum_back > a[i])
		{
			a3[i] = a[i];
			c3[i] = c[i];
			sum_back -= a[i];
		}
		else
		{
			a3[i] = sum_back;
			c3[i] = c[i];
		}
	}
	for(ll i = 1; i <= n / 2 + 1; i++)
	{
		a2[i] = a3[n - i + 1];
		c2[i] = c3[n - i + 1];
	}
	/////////////////////////////////////////处理成前后2个串 
//	cout << endl;
//	for(ll i = 1; i <= n / 2 + 1; i++){
//		cout << a1[i] << c1[i] << endl;
//	}
//	cout << endl;
//	for(ll i = 1; i <= n / 2 + 1; i++){
//		cout << a2[i] << c2[i] << endl;
//	}
	ll i = 1, j = 1;
	while(i <= n / 2 + 1 && j <= n / 2 + 1)
	{
		if(a[i] <= 0) i++;
		if(a[j] <= 0) j++;
//		for(ll k = 1; k <= n / 2 + 1; k++){
//			cout << a1[k] << c1[k] << " ";
//		}
//		cout << endl;
//		for(ll k = 1; k <= n / 2 + 1; k++){
//			cout << a2[k] << c2[k] << " ";
//		}
//		cout << endl << i << " " << j << " " << cnt << endl;
		if(c1[i] == c2[j])
		{
			if(a[i] <= 0) i++;
			if(a[j] <= 0) j++;
			if(a1[i] <= a2[j])
			{
				a2[j] -= a1[i];
				i++;
				if(a[i] <= 0) i++;
				if(a[j] <= 0) j++;
			}
			else
			{
				a1[i] -= a2[j];
				j++;
				if(a[i] <= 0) i++;
				if(a[j] <= 0) j++;
			}
		}
		else
		{
			if(a[i] <= 0) i++;
			if(a[j] <= 0) j++;
			if(a1[i] <= a2[j])
			{
				cnt += a1[i];
				a2[j] -= a1[i];
				i++;
				if(a[i] <= 0) i++;
				if(a[j] <= 0) j++;
			}
			else{
				cnt += a2[j];
				a1[i] -= a2[j];
				j++;
				if(a[i] <= 0) i++;
				if(a[j] <= 0) j++;
			}
		}
		
		if(a[i] <= 0) i++;
		if(a[j] <= 0) j++;
		
		
	}
	cout << cnt;
	return 0;
}
