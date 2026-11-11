#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int n=5e5+10;
int N,ans;
ll M;
ll A[n],S[n];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>N>>M;
	for(int i=1;i<=N;i++)
		cin>>A[i];
	sort(A+1,A+N+1);
	
	int lst=0;
	for(int i=1;i<=N;i++)
	{
		S[i]=S[i-1]+A[i];
		while(A[i]*(i-lst)-(S[i]-S[lst])>M)lst++;
//		cout<<i<<" "<<lst<<" "<<(A[i]*(i-lst)-(S[i]-S[lst]))<<"\n";
		ans=max(ans,i-lst);
	}
	cout<<ans;
	return 0;
}

