#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long m;
	string s;
}a[200005];
int n,cnt;
int find(long long id)
{
	for(int i=1;i<=n;i++)
	{
		if(a[i-1].m<id&&id<=a[i].m) return i;
    }
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].m>>a[i].s;
		a[i].m+=a[i-1].m;
	}
	for(int i=1;i<=a[n].m/2;i+=0)
    {
        int mid=(a[n].m+1)/2;
        int f1=find(i);
        int f2=find(a[n].m-i+1);
        int f3=find(mid);
		int s1=(f1==f3)?abs(mid-a[f1-1].m):a[f1].m-a[f1-1].m;
        int s2=(f2==f3)?a[f2].m-mid:a[f2].m-a[f2-1].m;
        int maxn=max(s1,s2);
        if(a[f1].s!=a[f2].s) cnt+=maxn;
        i+=maxn;
	}
	cout<<cnt;
	return 0;
} 
