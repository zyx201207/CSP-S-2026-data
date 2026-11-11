#include<bits/stdc++.h>
using namespace std;
long long n,m;
void sort_p(pair<long long,long long> a[]){
	for(long long i=0;i<n;i++){
		for(long long j=i+1;j<n;j++){
			int x=i,y=j;
			bool isx=false,isy=false;
			if(x>=1e9){
				x-=1e9;
			}
			if(y>=1e9){
				y-=1e9;
			}
			if(x>y){
				if(isx){
					if(isy){
						long long cnt=a[x].second;
						a[x].second=a[y].second;
						a[y].second=cnt;
					}else{
						long long cnt=a[x].second;
						a[x].second=a[y].first;
						a[y].first=cnt;
					}
				}else{
					if(isy){
						long long cnt=a[x].first;
						a[x].first=a[y].second;
						a[y].second=cnt;
					}else{
						long long cnt=a[x].second;
						a[x].second=a[y].second;
						a[y].second=cnt;
					}
				}
			}
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	pair<long long, long long > a[n];
	pair<long long, long long > l[n];
	for(long long i=0;i<n;i++){
		if(i>=1e9){
			int cnt=i-1e9;
			cin>>a[cnt].second;
			continue;
		}
		cin>>a[i].first;
	}
	sort_p(a);
	//
	//
//	for(long long i=0;i<n;i++){
//		if(i>=1e9){
//			int cnt=i-1e9;
//			cout<<a[cnt].second<<"\n";
//			continue;
//		}
//		cout<<a[i].first<<"\n";
//	}
	//
	//
	long long mid=a[n/2].first;
	for(long long i=0;i<n;i++){
		if(i>=1e9){
			int cnt=i-1e9;
			l[cnt].second=abs(a[cnt].second-mid);
		}
		l[i].first=abs(a[i].first-mid);
	}
	sort_p(l);
	//
	//
//	for(long long i=0;i<n;i++){
//		if(i>=1e9){
//			int cnt=i-1e9;
//			cout<<l[cnt].second<<"\n";
//			continue;
//		}
//		cout<<l[i].first<<"\n";
//	}
	//
	//
	long long cnt=0;
	long long num=0;
	for(long long i=0;i<n;i++){
		if(i>1e9){
			int xxxdfsah=i-1e9;
			if(cnt+l[xxxdfsah].second>m){
				break;
			}else{
				cnt+=l[xxxdfsah].second;
			}
		}else{
			if(cnt+l[i].second>m){
				break;
			}else{
				cnt+=l[i].first;
			}
		}
		num++;
//		cout<<cnt<<" "<<num<<"\n";
	}
	cout<<num-1;
	return 0;
}