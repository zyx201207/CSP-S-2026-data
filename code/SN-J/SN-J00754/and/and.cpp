//SN-J000754 余炜杰 西安辅轮中学 
#include<bits/stdc++.h>
#define int long long int
using namespace std;
int s[11451419];
int s1[11451419];

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b,maxm=0;
	cin>>a>>b;
	for(int i=0;i<a;i++){
		int m;
		cin>>m;
		s[m]++;
		maxm=max(maxm,m);
	}
	int cnt=0;
	for(int i=0;i<=maxm;i++){
		if(s[i]>0){
			s1[cnt]=i;
			cnt++;
		}
	}
	cnt--;
	if(cnt%2==0)cout<<s1[cnt/2];
	else cout<<s1[(cnt+1)/2];
	return 0;
}
