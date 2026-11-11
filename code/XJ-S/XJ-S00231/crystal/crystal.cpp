#include<bits/stdc++.h> 
using namespace std;
const int N = 5e5+5;
long long a[N];
int n;
long long m;
struct dif{
	long long v;
	long long d;
}diff[N];
bool cmp(dif a,dif b) {
	return a.d>b.d;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int mid = n/2;
	long long x = a[mid];
	long long ans = 0;
	for(int i=0;i<n;i++){
		diff[i].v=a[i]-x;
		diff[i].d=0-diff[i].v;	
	}
	sort(diff,diff+n,cmp);
	for(int i=0;i<n;i++){
		
		if(diff[i].v>=0){
			continue;
		}
		else{
			if(m-diff[i].d>=0){
				m-=diff[i].d;
				diff[i].v=0;
			}
			else{
				break;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(diff[i].v==0){
			ans++;
		}	
	}
	cout<<ans;
	return 0;
} 
