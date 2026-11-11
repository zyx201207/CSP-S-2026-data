#include<iostream>
#include<cstring>

using namespace std;

typedef long long LL;
const int N = 2e5 + 5;

char c[N];
LL vl[N];

LL res;
int n;

void sol()
{
	int l = 1;
	int r = n;
	LL sum_l = vl[l];
	LL sum_r = vl[r];
	LL nl = 0;
	LL nr = 0;
	
	while(l < r)
	{
//		cout << l << " " << r << endl;
		while(c[l] != c[r])
		{
//			cout << l << " " << r << endl;
			if(sum_l > sum_r)
			{
//				cout << "A" << endl;
				sum_l -= sum_r;
				res += sum_r;
				sum_r = 0;
			}
			else
			{
//				cout << res << " ";
				sum_r -= sum_l;
				res += sum_l;
				sum_l = 0;
//				cout << res << endl;
			}
			
			if(sum_l == 0)
			{
				++l;
				sum_l = vl[l];
			}
			
			if(sum_r == 0)
			{
				--r;
				sum_r = vl[r];
			}
			
			if(l >= r)
			{
				break;
			}
			
		}
		
		if(c[l] == c[r])
		{
			if(sum_l > sum_r)
			{
				sum_l -= sum_r;
				--r;
				sum_r = vl[r];
				continue;
			}
			else if(sum_l < sum_r)
			{
				sum_r -= sum_l;
				++l;
				sum_l = vl[l];
				continue;
			}
		}
		
		++l;
		--r;
		sum_l = vl[l];
		sum_r = vl[r];
	}
	
	return ;
}

int main()
{
//	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	
	
	
	cin >> n;
	
	for(int i = 1;i <= n;++i)
	{
		cin >> vl[i];
		cin >> c[i];
	}
	
	sol();
	
	cout << res;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
/*
fre
fcl
*/
