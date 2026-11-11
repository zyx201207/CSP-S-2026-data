#include<bits/stdc++.h>
using namespace std;

int main()
{
	//1.0s 1024MB
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;cin >> n;
	unsigned long long ans = 0;
	string a;
	string b;
	
	unsigned long long num2 = 0;
	unsigned long long num3 = 0;
	string c2;
	string c3;
	
	bool what = 1;
	bool what2 = 1;
	for(int i = 0;i < n;i++)
	{
		unsigned long long num;cin >> num;
		string c;cin >> c;
		if(i == 0){
			c2 = c;
			num3 = num;
		}
		
		if(c2 == c && num3 == num)
		{
			num2+=num;
			c3 += c;
			continue;
		}else if(c2 != c){
			what = 0;
		}else if(num3 != num){
			what2 = 0;
		}else{
			num2+=num;
			continue;
		}
		
		
		num += num2;
		ans += num;
		
		if(what||what2){
			continue;
		}
		
		for(int j  = 0;j < num;j++)
		{
			a += c;
		}
	}
	
	if(what){
		cout << '0' ;
		return 0;
	}
	if(what2){
		unsigned long long ans4 = 0;
		string d;
		for(int i = n-1;i > -1;i--)
		{
			d += c3[i];
		}
		for(int i = 0;i < n;i++)
		{
			if(d[i] != c3[i]) ans4++;
		}
		cout << ans4/2 * num3;
		return 0;
	}
	
	for(int i = ans-1;i > -1;i--)
	{
		b += a[i];
	}
	unsigned long long ans2 = 0;
	for(int i = 0;i < ans;i++)
	{
		if(a[i] != b[i]) ans2 ++;
	}
	
	cout << ans2/2;
	return 0;
}
