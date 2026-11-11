#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

short kin[200005];
long long nums[200005] ;
int main()
{
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	
	long long sum = 0;
    
    
	long long n;
	cin >> n;
	for (int i = 1 ; i <= n ; i ++)
	{
		char h ; 
		cin >> nums[i] >> h;
		kin[i] = h;
	}
	
	
int Lptr= 1 ;
int Rptr = n;
for(int du = 0 ; du < n ; du ++){
	if (kin[Lptr] != kin[Rptr])
	    {
			int miniu;
			miniu =fmin(nums[Lptr] , nums[Rptr]);
			sum = sum + miniu;
			nums[Rptr] = nums[Rptr] - miniu;
			nums[Lptr] = nums[Lptr] - miniu;
			if(nums[Lptr] ==0)Lptr++;
			if(nums[Rptr]==0)Rptr--;
		}
	else if (kin[Lptr] == kin[Rptr])
	      {
			int miniu;
			miniu =fmin(nums[Lptr] , nums[Rptr]);
			nums[Rptr] = nums[Rptr] - miniu;
			nums[Lptr] = nums[Lptr] - miniu;
			if(nums[Lptr] ==0)Lptr++;
			if(nums[Rptr]==0)Rptr--;
		}
	
}
cout << sum;
return 0;
}
