#include<bits/stdc++.h>
using namespace std;
const int Nax = 5e5+5;
int N;
long long A[Nax+5],S[Nax+5],M;
bool chk(int x)
{
	for(int i = x;i <= N;i++)
		if(A[i]*x-(S[i]-S[i-x]) <= M) return true;
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&N,&M);
	for(int i = 1;i <= N;i++) scanf("%lld",A+i);
	sort(A+1,A+N+1);
	for(int i = 1;i <= N;i++) S[i] = S[i-1]+A[i];
	int l = 1,r = N;
	while(r-l >= 2)
	{
		int mid = (l+r)>>1;
		if(chk(mid)) l = mid;
		else r = mid-1;
	}
	if(chk(r)) cout << r;
	else cout << l;
	return 0;
}