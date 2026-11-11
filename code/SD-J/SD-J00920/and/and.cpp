#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ulli unsigned lli
#define f(i, a, b) for(lli i = a; i <= b; i++)

const ulli MAX_SIZE = 2e5 + 5;

lli log2(lli x)
{
	return log(x) / log(2);
}

lli pow2(lli x)
{
	lli fac = 1;
	
	f(i, 1, x)
	{
		fac *= x;
	}
	
	return x;
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	lli n, m;
	lli a[MAX_SIZE];
	
	cin >> n >> m;
	f(i, 1, n)
	{
		cin >> a[i];
	}
//	{
//	if(n <= 20) // 测点 1 ~ 5 
//	{
//		
//	}
//	else if(n <= 2000) // 测点 6 ~ 10 
//	{
//		if(m == 1) // 测点 6 
//		{
//			lli answer = -1;
//			
//			f(i, 1, n)
//			{
//				answer = max(answer, a[i]);
//			}
//			
//			cout << answer << "\n";
//		}
//		else if(m == n) // 测点 7 
//		{
//			lli answer = a[1];
//			
//			f(i, 2, n)
//			{
//				answer &= a[i];
//			}
//			
//			cout << answer << "\n";
//		}
//		else if(m == 2) // 测点 8 ~ 10 
//		{
//			lli answer = -1;
//			
//			f(i, 1, n)
//			{
//				f(j, 1, n)
//				{
//					if(i != j)
//					{
//						answer = max(answer, a[i]&a[j]);
//					}
//				}
//			}
//			
//			cout << answer << "\n";
//		}
//	}
//	else if(n <= MAX_SIZE - 5) // 测点11 ~ 20 
//	{
//		if(m == n - 1) // 测点 11 ~ 12
//		{
//			lli answer = -1;
//			
//			f(i, 1, n)
//			{
//				
//			}
//		}
//		else // 测点 13 ~ 20
//		{
//			bool flag = true;
//			
//			f(i, 1, n)
//			{
//				flag = flag && (pow2(log2(a[i]+1)) == a[i] + 1);
//			}
//			
//			if(flag) // 测点 13
//			{
//				lli answer;
//				
//				sort(a+1, a+1+n);
//				
//				answer = a[n];
//				for(lli i = n - 1, cnt = 2; cnt <= m; i--, cnt++)
//				{
//					answer &= a[i];
//				}
//				
//				cout << answer << "\n";
//			}
//			else // 测点 14 ~ 20 
//			{
//				
//			}
//		}
//	}
//	}
	
	sort(a+1, a+1+n, [](lli x, lli y)
	{
		string a = bitset<64>(x).to_string(), b = bitset<64>(y).to_string();
		lli cnt_a = 0, cnt_b = 0;
		
		f(i, 0, 63)
		{
			cnt_a += (a[i] == '1');
			cnt_b += (b[i] == '1');
		}
		
		return cnt_a < cnt_b;
	});
	
	lli answer = a[n];
	for(lli i = n - 1; i >= n - m + 1; i--)
	{
		answer &= a[i];
	}
	
	cout << answer << "\n";
	
	return 0;
}
/*
5
3
31
3
1
15
7
*/
