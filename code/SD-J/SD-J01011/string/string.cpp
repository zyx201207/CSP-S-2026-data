#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char c[200005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	long long ans=0;
	long long cnt1=a[1],cnt2=a[n];
	for(int i=1,j=n;i<j;)
	{
		if(cnt1==cnt2)
		{
			if(c[i]!=c[j]) ans+=cnt1;
			i++;
			j--;
			if(i>=j) break;
			cnt1=a[i];
			cnt2=a[j];
		}
		else if(cnt1<cnt2)
		{
			if(c[i]!=c[j]) ans+=cnt1;
			cnt2-=cnt1;
			cnt1=0;
			i++;
			cnt1+=a[i];
		}
		else
		{
			if(c[i]!=c[j]) ans+=cnt2;
			cnt1-=cnt2;
			cnt2=0;
			j--;
			cnt2+=a[j];
		}
		if(i>=j) break;
		//cout<<i<<" "<<j<<" "<<cnt1<<" "<<cnt2<<" "<<ans<<endl;
	}
	cout<<ans;
	return 0;
}
/*
3
2 a
2 b
1 c

2*/
/*
2
2 a
3 a

0*/
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

3000000000*/
/*
8
10 a
88 b
99 c
113 d
5 a
8 b
6 t
9 g*/
