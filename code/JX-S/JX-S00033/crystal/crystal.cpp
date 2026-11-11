#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;

//crystal answer

long long n,m;
long long num[N];

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>num[i];
	}

	long long ans=0,last=m;
	sort(num,num+n);
	long long i=0,j=1;

	while(i<j){
		long long sub=(num[j]-num[j-1])*(j-i);
		// cout<<i<<" "<<j<<" "<<last<<" "<<sub<<" "<<j-i<<" "<<ans<<"\n";
		if(last>=sub){
			last-=sub;
			j++;
			if(j>n)break;
			ans=max(ans,j-i);
			
		}
		else{
			last+=(num[j-1]-num[i]);
			i++;
			if(i==j && j<n)j++;

		}

	}

	cout<<ans;

	return 0;
}