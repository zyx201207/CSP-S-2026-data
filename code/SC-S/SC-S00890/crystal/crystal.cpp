#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,i=1,j=1,mx=0,bc;
	long long cnt=0;
	int aok=1,bok=1;
	cin>>n>>m;
	a[0]=0;
	while(i<=n){
		cin>>a[i];
		if(i==2){
			bc=a[2]-a[1];
		}
		if(i>2){
			if(a[i]-a[i-1]!=bc)bok=0;
		}
		if(a[i]!=i)aok=0;
		i++;
	}
	if(aok){
		while(m>=0){
			m-=cnt;
			cnt++;
		}
		cout<<cnt-1;
		return 0;
	}
	if(bok){
		while(m>=0){
			m-=cnt*bc;
			cnt++;
		}
		cout<<cnt-1;
		return 0;
	}
	sort(a+1,a+n+1);
	i=1;

	
	
	while(j<=n){
		i=j;
		a[0]=0;
		cnt=0;
		while(i<=n){
			cnt=cnt+(a[i]-a[i-1])*(i-j);
			if(cnt>m)break;
			i++;
		}
		mx=max(mx,i-j);
		j++;
	}
	cout<<mx;

	return 0;
}
//RP++