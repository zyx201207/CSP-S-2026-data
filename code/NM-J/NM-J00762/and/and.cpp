#include"bits/stdc++.h"
using namespace std;

const int N = 2 * 1e5 + 10; 

long long n , m;
long long a[N];

long long popcount(int k)
{
	int sum = 0;
	
	while(k != 0)
	{
		if(k & 1) sum++;
		
		k >>= 1;
	}
	
	return sum;
}

int main(){
	
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	
	long long sum = LONG_LONG_MIN;
	for(int k = 1 ; k <= (1 << n) - 1 ; k++)
	{
		if(popcount(k) == m)
		{
			long long an = -1;
			
			long long x = k;
			
			long long idx = n;
			while(x != 0)
			{
				if(x & 1)
				{	
					//cout << a[idx] << " " ;
					if(an == -1) an = a[idx];
					else an = (an & a[idx]);
				}
				
				idx--;
				x >>= 1;
			}
			
			sum = max(an , sum);
			
		//	cout << endl << sum << " : " << an << endl << endl;
		}
	}
	
	cout << sum << endl;
	
	return  0;
}
