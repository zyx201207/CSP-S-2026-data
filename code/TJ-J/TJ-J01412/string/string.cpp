#include<bits/stdc++.h>
using namespace std;
int n;
struct node
{
	long long a;
	char c;
}arr[20005];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].a >> arr[i].c;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
