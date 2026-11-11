#include <iostream>
#include <algorithm>
struct son {
	int a;
	char c;
} s[200010];
long long cnt = 0;
int n;
using namespace std;
//9 7 a 18 b 35 c 40 d 55 e 20 d 70 c 1 b 9 a
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> s[i].a >> s[i].c;
	}
	int head_i = 1 , tail_i = n;
	int head_a = s[1].a , tail_a = s[n].a;
	while(head_i < tail_i)
	{
		int works = min(head_a , tail_a);
		if(s[head_i].c != s[tail_i].c)
		{
			cnt += works;
		}
		//cout << head_i <<' '<< head_a <<' '<< tail_i <<' '<< tail_a <<' '<< works <<' '<< cnt <<' '<< endl;
		if(head_a < tail_a)
		{
			head_i++;
			head_a = s[head_i].a;
			tail_a -= works; 
		}
		else if(head_a > tail_a)
		{
			tail_i--;
			tail_a = s[tail_i].a;
			head_a -= works; 
		}
		else
		{
			head_i++;
			tail_i--;
			head_a = s[head_i].a;
			tail_a = s[tail_i].a;
		}
	}
	cout << cnt << endl;
	return 0;
}
