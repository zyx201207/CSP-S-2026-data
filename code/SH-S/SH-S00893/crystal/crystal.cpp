#include<bits/stdc++.h>
using namespace std;
long long a[500005];
deque<int> d;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n;
	long long m;
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	for(int i=1;i<=n;i++){
//		for(int j=i+1;j<=n;j++){
//			if(a[i]>a[j]){
//				swap(a[i],a[j]);
//			}
//		}
//	}
	sort(a+1,a+n+1);
//	cout<<12345;
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<endl;
//	}
	
	long long maxx=0;
	
	d.push_back(1);
	long long tep=0;
	for(int i=2;i<=n;i++){
		long long si=d.size();
		while(tep+si*(a[i]-a[i-1])>m){
			tep=tep-(a[i-1]-a[d.front()]);
			d.pop_front();
			si--;
		}
		d.push_back(i);
		tep=tep+si*(a[i]-a[i-1]);
		si++;
		maxx=max(si,maxx);
	}
	cout<<maxx;
	return 0;
}
//5 293238795
//-33336 -40224 -96871 73355 9390
