#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,s=0,ss[200005],sss[200005];
char cc[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>ss[i]>>cc[i];
		s+=ss[i];
	}
	s/=2;
	for(int i=n-1,j=0;i>=0;i--,j++){
		sss[j]=ss[i];
	}
	int x=0,y=0,t1=0,t2=0,sum=0;
	for(int i=0;i<s;i++){
		if(ss[x]<t1){
			t1=0;
			x++;
		}
		if(sss[y]<t2){
			t2=0;
			y++;
		}
		if(cc[x]!=cc[n-y-1]){
			sum++;
		}
		t1++;
		t2++;
	}
	cout<<sum;
	return 0;
} 
