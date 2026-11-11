#include<bits/stdc++.h>
using namespace std;
int n;
long long q[200009],ans;
struct node{
	long long sum;
	char a;
}m[200009];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i].sum>>m[i].a;
		q[i]=q[i-1]+m[i].sum;
	}
	long long mid=q[n]/2;
	long long l=1,r=q[n],id1=1,id2=n;
	while(l<=mid&&r>=mid){
		while(l>q[id1])id1++;
		while(r<q[id2-1])id2--;
		if(m[id1].a!=m[id2].a){
			ans+=min(m[id1].sum,m[id2].sum);
		}
		l=min(mid+1,l+min(m[id1].sum,m[id2].sum)),r=max(mid-1,r-min(m[id1].sum,m[id2].sum));
	}
	cout<<ans;
	return 0;
}
