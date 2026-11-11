#include<bits/stdc++.h>
using namespace std;

const int N=1e5+50;
int a[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	int cnt=0;
	if(m==0){
		for(int i=0;i<n;i++){
			int sum=0;
			for(int j=i;j<n;j++){
				if(a[i]==a[j])sum++;
			}
			cnt=max(cnt,sum);
		}
	}
	cout<<cnt;
		
	return 0; 
}