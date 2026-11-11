#include <bits/stdc++.h>
using namespace std;
long long sum=0;
struct sum
{
	long long s;
	char z;
}q[200500];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>q[i].s>>q[i].z;
	}
	int r=n,l=1;
	while(l<r){
		if(q[l].z!=q[r].z)sum+=min(q[l].s,q[r].s);
		if(q[l].s>q[r].s){
			q[l].s-=q[r].s;
			r--;}
		else if(q[l].s<q[r].s){
			q[r].s-=q[l].s;
			l++;}
		else{
		    q[l].s=0;
			q[r].s=0;
			l++;
			r--;} 
	}
	cout<<sum;
	return 0;
}
