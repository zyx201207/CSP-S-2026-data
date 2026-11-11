#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>a(n,0);
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a.begin(),a.end(),cmp);
	if(m==1){
		cout<<a[0];
	}
	else if(m==n){
		int s=a[0];
		for(int i=1;i<n;i++)s&=a[i];
		cout<<s;
	}
	else if(m==2){
		int s=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j)continue;
				s=max(s,a[i]&a[j]);
			}
		}
		cout<<s;
	}
	else if(n<=20){
		int s=0;
		for(int mask=1;mask<(1<<n);mask++){
			int c=(1<<n)-1;
			int cnt=0;
			for(int i=0;i<n;i++){
				if(mask&(1<<i)){
					cnt++;
					c&=a[i];
				}
			}
			if(cnt!=m)continue;
			s=max(s,c);
		}
		cout<<s;
	}
	else{
		cout<<a[m-1];
	}
	return 0;
}
