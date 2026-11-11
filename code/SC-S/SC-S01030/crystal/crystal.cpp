#include<iostream>
using namespace std;
int n;
long long m;
long long a[500010];
long long b[500010];
long long arr[500010];
void he(int l,int mid,int r){
	int i = l,j = mid + 1,pos = l;
	while(i <= mid&&j <= r)
		if(a[i] < a[j])
			arr[pos++] = a[i++];
		else
			arr[pos++] = a[j++];
	while(i <= mid)
		arr[pos++] = a[i++];
	while(j <= r)
		arr[pos++] = a[j++];
	for(pos = l;pos <= r;pos++)
		a[pos] = arr[pos];
}
void _sort(int l,int r){
	int mid = (l + r) / 2;
	if(l < r){
		_sort(l,mid);
		_sort(mid + 1,r);
	}
	he(l,mid,r);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i < n;i++)
		cin>>a[i];
	_sort(0,n - 1);
	for(int i = 1;i < n;i++)
		b[i] = (a[i] - a[i - 1]) * i;
	long long ml = 0,pos = 0,l = 1;
	long long sum = 0;
	for(int i = 1;i < n;i++){
		sum += (i - pos) * (a[i] - a[i - 1]);
		l++;
		while(sum > m)
			l--,sum -= a[i] - a[pos++];
		ml = max(ml,l);
	}
	cout<<ml;
	return 0;
}