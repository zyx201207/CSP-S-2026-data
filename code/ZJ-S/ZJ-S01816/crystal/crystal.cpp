#include<bits/stdc++.h>
using namespace std;

int n;
long long m;
int b[500005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int county=0;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i]==i){
			county++;
		}
	}

	if(county==n){
		int summer=0;
		int answer;
		for(int cnt=1;cnt<=n;cnt++){
			summer+=cnt;
			if(summer>m){
				break;
			}
			answer=cnt+1;
		}
		cout<<answer;
		return 0;
	}

	sort(b+1,b+n+1);
	int maxn=0;
	for(int j=n;j>=2;j--){
		int sum=0;
		for(int cnt=1;cnt<=j;cnt++){
			sum=sum+b[j]-b[j-cnt];
			if(sum>m){
				break;
			}
			maxn=max(maxn,cnt+1);
		}
	}
	cout<<maxn;
	return 0;
}